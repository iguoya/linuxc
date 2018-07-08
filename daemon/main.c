#include <syslog.h>
#include <unistd.h>
int main() {
    openlog("tiger's daemon", LOG_PID, LOG_DAEMON);

    for(int i = 0; 1; ++i) {
        syslog(LOG_INFO, "tiger log output %d \n", i);
        syslog(LOG_WARNING, "happen unusual sth %d \n", i);
        syslog(LOG_ERR, "ooh, bad things ..... %d \n", i);
        sleep(2);
    }
    return 0;
}