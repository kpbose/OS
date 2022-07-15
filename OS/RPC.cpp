#include <rpc/rpc.h>
  #include "void.h"

main()
  {
      CLIENT *pclnt;
void   *pVoid;

char    Host[256];

      /* Get the name of the host running the server. */

gethostname(Host, 256);

      /* Connect to the server. */

pclnt = clnt_create(Host, MJLPROG, MJLVERS, "udp");

      /* Issue a request to the server. */

      void_1(pVoid, pclnt);

      /* Disconnect from the server. */

clnt_destroy(pclnt);

  }
void *void_1_svc(void *pVoid,  structsvc_req *X)
  {
printf("Function called without passing arguments\n");
  }
{
int INTEGER(int) = 1;

    } = 1;
  } = 0x20000001
