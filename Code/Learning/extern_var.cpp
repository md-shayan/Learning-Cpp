#include <cstdio>

extern int battery = 70;

void charge(int upto) // object's % of battery charged
{
       battery = battery + upto;
       if (battery>100)
       {
              printf("Warning! Battery is overcharged.\n");
              battery=100;
       }
}

void drain(int upto) // object's % of battery drained
{
       battery = battery - upto;
       if (battery<1)
       {
              printf("Warning! Out of power\n");
              battery=0;
       }
}

int main()
{
       printf("Current Battery Level:%d%\n", battery);
       charge(31);
       printf("Current Battery Level:%d%\n", battery);
       drain(109);
       printf("Current Battery Level:%d%\n", battery);
       return 0;
}