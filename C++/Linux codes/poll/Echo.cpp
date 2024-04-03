#include <iostream>
#include <poll.h>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
    struct pollfd fds[1];

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    while (true) {
        int ret = poll(fds, 1, -1);
        if (ret == -1) {
            perror("poll");
            return 1;
        }

        if (fds[0].revents & POLLIN) {
            char buffer[1024];
            ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));
            if (bytesRead == -1) {
                perror("read");
                return 1;
            }
            string data = string(buffer, bytesRead);
            cout << "Input: " << data << endl;
        
        }

    }

    return 0;
}
