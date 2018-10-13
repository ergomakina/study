//#include <stdio.h>  // printfしたければinclude #include <stdlib.h>  // strtof #include <string.h> #include <time.h> #include <fcntl.h> #include <unistd.h> #include <errno.h> #include <locale.h>  /**  * Linuxの起動時間を取得する **/ time_t getLinuxUptime() {     int fd;     char buf[64];     char *endptr, *saveptr;     ssize_t len;     time_t get_time = 0;     char *savelocale;      fd = open("/proc/uptime", O_RDONLY);     if (fd < 0){ //        printf("cannot open proc uptime: %s", strerror(errno));         return 0;     }     lseek(fd, 0L, SEEK_SET);      savelocale = strdup(setlocale(LC_NUMERIC, NULL));     if (savelocale) {         setlocale(LC_NUMERIC,"C");     }      len = read(fd, buf, sizeof(buf)-1);     if (len < 0) {         buf[0] = '\0'; //        printf("cannot read proc uptime: %s", strerror(errno));     } else {         buf[len] = '\0';     }      if (savelocale) {         setlocale(LC_NUMERIC, savelocale);         free(savelocale);     }      close(fd);      if (strtok_r(buf, " ", &saveptr) != NULL) {         get_time = (time_t)strtof(buf, &endptr);         if (*endptr != '\0') { //            printf("linux uptime parse miss. buffer=%s", buf);         }     }  //    printf("Linux Uptime: %lu\n", (unsigned long)get_time);      return get_time; }
