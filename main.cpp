
#include "MData.h"




int main() {



    MData kal(2020, 12, 31);
    MData kal1(2020, 1, 1);
    MData ka(1, 12, 31);
    kal.to_String();
    ka.to_String();
    (kal+ka).to_String();
    (kal1+=100000).to_String();




    return 0;
}
