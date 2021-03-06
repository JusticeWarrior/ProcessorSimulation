#include "FEL.h"
#include "SimulationData.h"
#include "Server.h"
#include "ListNode.h"
#include "Control.h"
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "test1.txt"

int main(int argc, char** argv)
{
  FEL* fel = Control_InitializeModeOne(0.009, 0.01, 0.02, 2);
  ListNode_PrintList(fel->EventList, "SubTaskArrivals");
  printf("Load Balancing Factor is: %f", fel->LBF);
  return EXIT_SUCCESS;
}
