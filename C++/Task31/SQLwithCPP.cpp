#include <iostream>
#include <mysql.h>

using namespace std;

int main() {
  MYSQL* conn;
  conn = mysql_init(0);

  if (conn == nullptr) {
    cerr << "mysql_init failed!" << endl;
    return 1;
  }

  conn = mysql_real_connect(conn, "localhost", "Stark", "Ube@1402", "db1", 3306, NULL, 0);

  if (conn) 
  {
    string insert_query = "INSERT INTO Employee(e_id, e_name, e_dept, E_salary, E_xp) VALUES (7, 'Mahi', 'PHY', 800000.0, '17 Years')";
    int query_state = mysql_query(conn, insert_query.c_str());

    if (query_state != 0) {
      cerr << "Insert query failed: " << mysql_error(conn) << endl;
    }

    string update_query = "UPDATE Employee SET E_salary=80000 WHERE e_id=1";
    query_state = mysql_query(conn, update_query.c_str());

    if (query_state != 0) {
      cerr << "Update query failed: " << mysql_error(conn) << endl;
    }

    string delete_query = "DELETE FROM Employee WHERE e_id=1";
    query_state = mysql_query(conn, delete_query.c_str());

    if (query_state != 0) {
      cerr << "Delete query failed: " << mysql_error(conn) << endl;
    }

    string select_query = "SELECT * FROM Employee";
    query_state = mysql_query(conn, select_query.c_str());

    if (query_state == 0) {
      MYSQL_RES* result = mysql_store_result(conn);

      if (result) {
        while (MYSQL_ROW row = mysql_fetch_row(result)) {
          cout << row[0] << " " << row[1] <<" "<<row[2]<<" "<<row[3]<< endl;
        }

        mysql_free_result(result);
      } else {
        cerr << "Failed to store result set: " << mysql_error(conn) << endl;
      }
    } else {
      cerr << "Select query failed: " << mysql_error(conn) << endl;
    }
  } else {
    cout << "Failed to connect to the database." << endl;
  }

  mysql_close(conn);

  return 0;
}
