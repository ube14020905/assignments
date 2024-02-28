#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main()
{
    try
    {

        const std::string url = "mysql://Ubedulla:'Ube@1402'@localhost";
        const std::string schema_name = "db1";

        Session session(url);
        cout << "Connected to MySQL Server." << endl;

        Schema schema = session.getSchema(schema_name);

        Table table = schema.getTable("Employee");
        // Insert a record
        table.insert("e_id", "e_name", "e_dept", "E_salary", "E_xp")
            .values(7, "Mahi", "PHY", 800000.0, "17 Years")
            .execute();

        // Update a record
        table.update()
            .set("E_salary", 80000)
            .where("e_id = 4")
            .execute();

        RowResult result = table.select("*").execute();
        for (const Row &row : result)
        {
            cout << row[0].get<int>() << ", "
                 << row[1].get<std::string>() << ", "
                 << row[2].get<std::string>() << ", "
                 << row[3].get<double>() << endl;
        }

        table.remove()
            .where("e_id = 1")
            .execute();

        // Close the session
        session.close();
        cout << "Disconnected from MySQL Server." << endl;
    }
    catch (const Error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}