//============================================================================
// Name        : Assignment1.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	double temperature;
	int statuscode;
	cout<<"enter the temperature";
	cin>>temperature;

    if(temperature <0)
    {
    	statuscode=-1;
    }
    else if(temperature<30)
    {
    	statuscode=0;
    }
    else if(temperature<45){
    	statuscode=1;
    }else if(temperature<60){
    	statuscode=2;
    }else{
    	statuscode=3;
    }
      double fahrenheit=(temperature*9/5)+32;
      cout<<"temperature: "<<temperature<<"c/"<<fahrenheit<<"F"<<endl;
      cout<<"status:";
      switch(statuscode)
      {
      case -1:
    	  cout<<"sensor_error";
    	  break;
      case 0:
          	  cout<<"normal";
          	  break;
      case 1:
          	  cout<<"warning";
          	  break;
      case 2:
          	  cout<<"critical";
          	  break;
      case 3:
          	  cout<<"shutdown";
          	  break;
      }
      cout<<endl;
      cout<<"action:";
      switch (statuscode){
      case -1:
          	  cout<<"sensor fault-chech wiring";
          	  break;
      case 0:
          	  cout<<"no action required ";
          	  break;
      case 1:
          	  cout<<"alert sent to supervisor:";
          	  break;
      case 2:
          	  cout<<"cooling system triggered";
          	  break;
      case 3:
          	  cout<<"emergency shutdown initiated";
          	  break;
      }
      cout <<endl;
      cout<<"reading:"<<(temperature>=25?"above average":"below average")<<endl;


	return 0;
}
