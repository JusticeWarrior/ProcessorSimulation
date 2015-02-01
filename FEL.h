#ifndef FEL_INCLUDED
#define FEL_INCLUDED 

typedef struct FEL_st FEL;

#include "Event.h"
#include "Queue.h"
#include "SimulationData.h"
#include "ListNode.h"
#include "Server.h"
#include <math.h>
#include <stdlib.h>

struct FEL_st{
  //The number of people that still have to arrive in each priority queue
  int* ArrivalsLeft;

  //The variables used in the exponential distribution functions
  float* Lambda;
  float Mu;

  //The list of events, ordered by time, of events that will occur in the future
  ListNode* EventList;
};

//Create an FEL structure with the given values
FEL* FEL_Create(int totalArrivals, float mu, float lambda0, float lambda1);

//Destroy the FEL structure
void FEL_Destroy(FEL* FutureEvents);

//Randomly generate a new arrival event of the given prority using the time of
//The privous arrival.  If the previousTime is <0, then the event will be
//Scheduled to occur at t=0
Event* FEL_GenerateRandomArrival(FEL* futureEvents, int  priority, int previousTime);

//Generate a new departute event based off of a given arrival event
Event* FEL_GenerateDeparture(Event* arrival, int currentTime);

//Add an event that already exists to the FEL strucure
void FEL_AddEvent(FEL* futureEvents, Event* event);

//Returns a 1 if there are not more events on the queue
int FEL_IsEmpty(FEL* futureEvents);

//Return the first event from the FEL and remove it from the FEL list
Event* FEL_PopEvent(FEL* futureEvents);

#endif /* FEL_INCLUDED */
