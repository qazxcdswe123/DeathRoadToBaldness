#include "run.h"

int main()
{
    BaseRun *pBaseRun;
    CarRun *pCarRun = new CarRun;
    DogRun *pDogRun = new DogRun;
    PeopleRun *pPeopleRun = new PeopleRun;

    pBaseRun = pCarRun;
    pBaseRun->run();

    pBaseRun = pDogRun;
    pBaseRun->run();

    pBaseRun = pPeopleRun;
    pBaseRun->run();

    delete pCarRun;
    delete pDogRun;
    delete pPeopleRun;
}