#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

static fstream p;

class general
{

public:

    string team1,team2,location,tosswon,tosschoice,matchtype;
    int matchno,choice,totmat;


     general()
    {
        team1='0';
        team2='0';
        location='0';
        tosswon='0';
        tosschoice='0';
        matchtype="The Final";
        matchno=0;
        choice=0;
        totmat=48;

    }

    void enterdata()
    {
        cout<<"\n Enter Team-1 Name: "<<endl;
        cin>>team1;
        cout<<"\n Enter Team-2 Name: "<<endl;
        cin>>team2;

        cout<<"\n Enter Venue of match "<<endl;
        cin>>location;

        cout<<"\n Enter Match Number: "<<endl;
        cin>>matchno;
    }

    void toss()
    {
        cout<<"\n \t \t \t  Enter Toss Details "<<endl;
        cout<<"\n Enter which team won the toss "<<endl;
        cin>>tosswon;
        cout<<"\n Enter Choice of the team "<<endl;
        cin>>tosschoice;

        if(tosswon==team1 && tosschoice=="bat")
            choice=1;
        if(tosswon==team1 && tosschoice=="bowl")
            choice=2;
        if(tosswon==team2 && tosschoice=="bat")
            choice=3;
        if(tosswon==team2 && tosschoice=="bowl")
            choice=4;
    }

    void display1()
    {
         p<<"\n \n \n \t \t \t Match No: "<<matchno<<" Out of "<<totmat<<" ( "<<matchtype<<" match )"<<endl<<endl;
         p<<"\t \t \t"<<team1<<" VS "<<team2<<endl<<endl;
        p<<"Venue: "<<location<<endl<<endl;

        p<<"\n   Toss details: \t"<<endl;
        p<<'\t'<<tosswon<<" Won the toss and choose to "<<tosschoice<<endl<<endl;
    }
};

class team : public general
{
public:

    string batsman[12],bowler[12],teamstatus,team11,team12;
    int batruns[12],batballs[12],bowlruns[10],bowlwickets[10],bowlmaiden[10],teamruns,teamwickets,extras,n1,n2,i;
    int choice1;
    double teamovers,strikerate[12],bowlover[12],t,economy[10],runrate;
    int k,a;

    team()
    {
        teamstatus='0';
        teamruns=0;
        teamwickets=0;
        teamovers=0;
        team11='0';
        team12='0';
        k=0;
        a=0;
        choice1=0;
        runrate=0;

    }

    team(const team &k1)
    {
        team11=k1.team1;
        team12=k1.team2;
        choice1=k1.choice;
    }


    void batting()
    {

        cout<<"\n Team status "<<" ( Allout (or) Notout ) "<<endl;
        cin>>teamstatus;
        cout<<"\n \n \n \t \t \t \n \n \n \t \t \t Enter batsman details "<<endl;
        cout<<"\n Enter batsman Name , Runs scored , Balls faced "<<endl<<endl;
    if(teamstatus=="Allout")
        {
            int i;
          for(i=0;i<11;i++)
            {
            cout<< " Enter details of batsman "<<i+1<<endl;
            cin>>batsman[i];
            cin>>batruns[i];
            cin>>batballs[i];

           if((batruns[i]==0) | (batballs[i]==0))
            strikerate[i]=0;
            else
            {
            t=batruns[i]*100;
            strikerate[i]=t/batballs[i];
            }
        }
        teamwickets=10;
        }

    else
        {
            for(i=0,k=0;k!=2;i++)
        {
            cout<< " Enter details of batsman "<<i+1<<endl;
            cin>>batsman[i];
            ++a;
            for(int j=0;j<batsman[i].length();j++)
            {
                if(batsman[i].at(j)=='*')
                {
                    ++k;
                }
            }
            cin>>batruns[i];
            cin>>batballs[i];
            ++teamwickets;
            if((batruns[i]==0) | (batballs[i]==0))
               strikerate[i]=0;
            else
            {
            t=batruns[i]*100;
            strikerate[i]=t/batballs[i];
            }
        }

            teamwickets-=2;
        }

    }

     void bowling()
     {

         cout<<" \n \n \n \t \t \t Enter bowler details "<<endl;
         cout<<"\n Enter no of bowlers "<<endl;
         cin>>n2;
         cout<<"\n Enter details of bowler: "<<endl;
         cout<<"\n Enter bowler Name , Bowled overs , Runs given , Wickets taken , Maiden overs "<<endl<<endl;
         for(i=0;i<n2;i++)
         {
             cout<<"\n Enter bowler details "<<endl;
             cin>>bowler[i];
             cin>>bowlover[i];
             cin>>bowlruns[i];
             cin>>bowlwickets[i];
             cin>>bowlmaiden[i];
         }
         for(i=0;i<n2;i++)
            economy[i]=bowlruns[i]/bowlover[i];

         cout<<"\n Enter Extras given "<<endl;
         cin>>extras;


     }

      void displaybat()
    {

        p<<'\n'<<'\n'<<'\n'<<'\t'<<'\t'<<"Team score: "<< teamruns << " - "<< teamwickets <<"  ("<<setprecision(3)<<teamovers<<")"<<"\t \t"<<setprecision(3)<<"RR: "<<runrate;
        p<<'\n'<<'\n';

        p<<" \n\t Batsman details \n"<<endl;
        p<<"Name"<<'\t'<<'\t'<<'\t'<<"Runs"<<'\t'<<'\t'<<'\t'<<"Balls"<<'\t'<<'\t'<<'\t'<<"Strike rate"<<'\n';
        if(teamstatus=="Allout")
        {
        for(i=0;i<11;i++)
        {
            p<<batsman[i];
            p<<'\t'<<'\t'<<'\t'<<batruns[i];
            p<<'\t'<<'\t'<<'\t'<<batballs[i];
            p<<'\t'<<'\t'<<'\t'<<setprecision(5)<<strikerate[i];
            p<<'\n';
        }
        }

        else
        {
            for(i=0;i<a;i++)
            {
            p<<batsman[i];
            p<<'\t'<<'\t'<<'\t'<<batruns[i];
            p<<'\t'<<'\t'<<'\t'<<batballs[i];
            p<<'\t'<<'\t'<<'\t'<<setprecision(5)<<strikerate[i];
            p<<'\n';
            }
        }
        p<<endl;
    }

    void displaybowl()
    {
        p<<" \n \n \t Bowler details \n"<<endl;
        p<<"Name"<<'\t'<<'\t'<<'\t'<<"Overs"<<'\t'<<'\t'<<'\t'<<"Runs"<<'\t'<<'\t'<<'\t'<<"Wickets"<<'\t'<<'\t'<<'\t'<<"Maiden"<<'\t'<<'\t'<<'\t'<<"Economy"<<'\n';

        for(i=0;i<n2;i++)
         {
             p<<bowler[i];
             p<<'\t'<<'\t'<<'\t'<<setprecision(3)<<bowlover[i];
             p<<'\t'<<'\t'<<'\t'<<bowlruns[i];
             p<<'\t'<<'\t'<<'\t'<<bowlwickets[i];
             p<<'\t'<<'\t'<<'\t'<<bowlmaiden[i];
             p<<'\t'<<'\t'<<'\t'<<setprecision(3)<<economy[i];
             p<<'\n';
         }
         p<<"\t \t \t \t \t \t \t \t \t \t \t \t \t \t"<<" Extras "<<": "<<extras<<endl;
    }

   friend team team1cal(team &r1,team &r2);
   friend team team2cal(team &r2,team &r1);
   friend team teamsort(team &r1,team &r2);
   friend team teamres(team &r1,team &r2);

}r1,r2;

     team team1cal(team &r1,team &r2)
   {
    int i;
  if(r1.teamstatus=="Allout")
      {
         for(i=0;i<11;i++)
             r1.teamruns+=r1.batruns[i];
             r1.teamruns+=r2.extras;

       }

    else
       {
            for(i=0;i<r1.a;i++)
             r1.teamruns+=r1.batruns[i];
             r1.teamruns+=r2.extras;

       }
        for(i=0;i<r2.n2;i++)
             r1.teamovers+=r2.bowlover[i];

             r1.runrate=r1.teamruns/r1.teamovers;



             return r1,r2;

}


    team team2cal(team &r2,team &r1)
   {
    int i;
  if(r2.teamstatus=="Allout")
      {
         for(i=0;i<11;i++)
             r2.teamruns+=r2.batruns[i];
             r2.teamruns+=r1.extras;
       }
    else
       {
            for(i=0;i<r2.a;i++)
             r2.teamruns+=r2.batruns[i];
             r2.teamruns+=r1.extras;

       }
        for(i=0;i<r1.n2;i++)
             r2.teamovers+=r1.bowlover[i];

             r2.runrate=r2.teamruns/r2.teamovers;


             return r2,r1;

}


team teamsort(team &r1,team &r2)
{
    int i,j;
    string batsman1[20],batsman2[20],bowler1[20],bowler2[20],disbatsman1[20],disbatsman2[20],disbowler1[20],disbowler2[20];
    int batruns1[20],batruns2[20],batballs1[20],batballs2[20],bowlruns1[20],bowlruns2[20],bowlwicket1[20],bowlwicket2[20],disbatruns1[20],disbatruns2[20],disbatballs1[20],disbatballs2[20],disbowlruns1[20],disbowlruns2[20],disbowlwickets1[20],disbowlwickets2[20];
    float bowlovers1[20],bowlovers2[20],disbowlovers1[20],disbowlovers2[20];
    string t11,t12,t1;
    int t21,t22,t31,t32,t2,t3;
    float t41,t42,t4;



                                /**************************BAT CALCULATION*****************************************/


             /**------------BAT RUNS_INITIALIZATION----------------------**/


    //_____________________TEAM-1_______________________





    if(r1.teamstatus=="Allout")
    {
        for(i=0;i<12;i++)
        {
           batsman1[i]=r1.batsman[i];
           batruns1[i]=r1.batruns[i];
           batballs1[i]=r1.batballs[i];
        }
    }
    else
    {
        for(i=0;i<r1.a;i++)
        {

            batsman1[i]=r1.batsman[i];
            batruns1[i]=r1.batruns[i];
            batballs1[i]=r1.batballs[i];
        }
    }





    //_____________________TEAM-2_______________________









    if(r2.teamstatus=="Allout")
    {
        for(i=0;i<12;i++)
        {
        batsman2[i]=r2.batsman[i];
        batruns2[i]=r2.batruns[i];
        batballs2[i]=r2.batballs[i];
        }
    }
    else
    {

    for(i=0;i<r2.a;i++)
    {
        batsman2[i]=r2.batsman[i];
        batruns2[i]=r2.batruns[i];
        batballs2[i]=r2.batballs[i];
    }

    }







     /**------------BAT RUNS_SORTING----------------------**/

     //_____________________TEAM-1_______________________





     if(r1.teamstatus=="Allout")
     {
         for(i=0;i<11;i++)
         {
             for(j=0;j<10-i;j++)
             {
                 if(batruns1[j]<batruns1[j+1])
                 {
                     t31=batruns1[j];
                     batruns1[j]=batruns1[j+1];
                     batruns1[j+1]=t31;
                     t11=batsman1[j];
                     batsman1[j]=batsman1[j+1];
                     batsman1[j+1]=t11;
                     t21=batballs1[j];
                     batballs1[j]=batballs1[j+1];
                     batballs1[j+1]=t21;
                 }

             }
         }

     }
     else
     {
         for(i=0;i<r1.a;i++)
         {
             for(j=0;j<r1.a-i-1;j++)
             {
                 if(batruns1[j]<batruns1[j+1])
                 {
                     t31=batruns1[j];
                     batruns1[j]=batruns1[j+1];
                     batruns1[j+1]=t31;
                     t11=batsman1[j];
                     batsman1[j]=batsman1[j+1];
                     batsman1[j+1]=t11;
                     t21=batballs1[j];
                     batballs1[j]=batballs1[j+1];
                     batballs1[j+1]=t21;
                 }
             }
         }

     }



      //_____________________TEAM-2_______________________






     if(r2.teamstatus=="Allout")
     {
        for(i=0;i<11;i++)
         {
             for(j=0;j<10-i;j++)
             {
                 if(batruns2[j]<batruns2[j+1])
                 {
                     t32=batruns2[j];
                     batruns2[j]=batruns2[j+1];
                     batruns2[j+1]=t32;
                     t12=batsman2[j];
                     batsman2[j]=batsman2[j+1];
                     batsman2[j+1]=t12;
                     t22=batballs2[j];
                     batballs2[j]=batballs2[j+1];
                     batballs2[j+1]=t22;
                 }

             }
         }
     }
     else
     {
         for(i=0;i<r2.a;i++)
         {
             for(j=0;j<r2.a-i-1;j++)
             {
                 if(batruns2[j]<batruns2[j+1])
                 {
                      t32=batruns2[j];
                     batruns2[j]=batruns2[j+1];
                     batruns2[j+1]=t32;
                     t12=batsman2[j];
                     batsman2[j]=batsman2[j+1];
                     batsman2[j+1]=t12;
                     t22=batballs2[j];
                     batballs2[j]=batballs2[j+1];
                     batballs2[j+1]=t22;
                 }

             }
         }
     }



              /**------------BAT RUNS_INITIALIZE(DISPLAY)----------------------**/




    //_____________________TEAM-1_______________________


      for(i=0;i<4;i++)
      {
          disbatsman1[i]=batsman1[i];
          disbatruns1[i]=batruns1[i];
          disbatballs1[i]=batballs1[i];
      }



     //_____________________TEAM-2_______________________





          for(i=0;i<4;i++)
      {
          disbatsman2[i]=batsman2[i];
          disbatruns2[i]=batruns2[i];
          disbatballs2[i]=batballs2[i];
      }


               /**************************BOWL CALCULATION*****************************************/


               /**------------BOWLING_INITIALIZATION----------------------**/


            //_____________________TEAM-1_______________________


         for(i=0;i<r1.n2;i++)
         {
             bowler1[i]=r1.bowler[i];
             bowlwicket1[i]=r1.bowlwickets[i];
             bowlruns1[i]=r1.bowlruns[i];
             bowlovers1[i]=r1.bowlover[i];
         }

            //_____________________TEAM-2_______________________


         for(i=0;i<r2.n2;i++)
         {
             bowler2[i]=r2.bowler[i];
             bowlwicket2[i]=r2.bowlwickets[i];
             bowlruns2[i]=r2.bowlruns[i];
             bowlovers2[i]=r2.bowlover[i];
         }


         /**------------BOWLING_SORTING----------------------**/





            //_____________________TEAM-1_______________________


        for(i=0;i<r1.n2;i++)
        {
            for(j=0;j<r1.n2-i-1;j++)
            {
                if(bowlwicket1[j]<bowlwicket1[j+1])
                {
                    t1=bowler1[j];
                    bowler1[j]=bowler1[j+1];
                    bowler1[j+1]=t1;
                    t2=bowlwicket1[j];
                    bowlwicket1[j]=bowlwicket1[j+1];
                    bowlwicket1[j+1]=t2;
                    t3=bowlruns1[j];
                    bowlruns1[j]=bowlruns1[j+1];
                    bowlruns1[j+1]=t3;
                    t4=bowlovers1[j];
                    bowlovers1[j]=bowlovers1[j+1];
                    bowlovers1[j+1]=t4;
                }

                else if(bowlwicket1[j]==bowlwicket1[j+1])
                {
                    if(bowlruns1[j]>bowlruns1[j+1])
                    {
                      t1=bowler1[j];
                    bowler1[j]=bowler1[j+1];
                    bowler1[j+1]=t1;
                    t2=bowlwicket1[j];
                    bowlwicket1[j]=bowlwicket1[j+1];
                    bowlwicket1[j+1]=t2;
                    t3=bowlruns1[j];
                    bowlruns1[j]=bowlruns1[j+1];
                    bowlruns1[j+1]=t3;
                    t4=bowlovers1[j];
                    bowlovers1[j]=bowlovers1[j+1];
                    bowlovers1[j+1]=t4;
                    }

                }
            }
        }



         //_____________________TEAM-2_______________________


        for(i=0;i<r2.n2;i++)
        {
            for(j=0;j<r2.n2-i-1;j++)
            {
                if(bowlwicket2[j]<bowlwicket2[j+1])
                {
                    t1=bowler2[j];
                    bowler2[j]=bowler2[j+1];
                    bowler2[j+1]=t1;
                    t2=bowlwicket2[j];
                    bowlwicket2[j]=bowlwicket2[j+1];
                    bowlwicket2[j+1]=t2;
                    t3=bowlruns2[j];
                    bowlruns2[j]=bowlruns2[j+1];
                    bowlruns2[j+1]=t3;
                    t4=bowlovers2[j];
                    bowlovers2[j]=bowlovers2[j+1];
                    bowlovers2[j+1]=t4;
                }

                else if(bowlwicket2[j]==bowlwicket2[j+1])
                {
                    if(bowlruns2[j]>bowlruns2[j+1])
                    {
                      t1=bowler2[j];
                    bowler2[j]=bowler2[j+1];
                    bowler2[j+1]=t1;
                    t2=bowlwicket2[j];
                    bowlwicket2[j]=bowlwicket2[j+1];
                    bowlwicket2[j+1]=t2;
                    t3=bowlruns2[j];
                    bowlruns2[j]=bowlruns2[j+1];
                    bowlruns2[j+1]=t3;
                    t4=bowlovers2[j];
                    bowlovers2[j]=bowlovers2[j+1];
                    bowlovers2[j+1]=t4;
                    }

                }
            }
        }



        /**------------BOWLING_INITIALIZE(DISPLAY)----------------------**/


            //_____________________TEAM-1_______________________

            for(i=0;i<4;i++)
            {
                disbowler1[i]=bowler1[i];
                disbowlwickets1[i]=bowlwicket1[i];
                disbowlruns1[i]=bowlruns1[i];
                disbowlovers1[i]=bowlovers1[i];
            }

             //_____________________TEAM-2_______________________

            for(i=0;i<4;i++)
            {
                disbowler2[i]=bowler2[i];
                disbowlwickets2[i]=bowlwicket2[i];
                disbowlruns2[i]=bowlruns2[i];
                disbowlovers2[i]=bowlovers2[i];
            }




                    /**************************SUMMARY CALCULATION*****************************************/


if((r1.choice1==1)||(r1.choice1==4))
    {
        p<<"\n \n \n "<<"\t \t \t "<<"MATCH SUMMARY"<<'\n'<<'\n'<<endl;
        if(r1.teamwickets==10)
        p<<'\t'<<"  "<<r1.team11<<"\t \t \t "<<r1.teamruns<<" ("<<r1.teamovers<<")"<<endl;
        else
        p<<'\t'<<"  "<<r1.team11<<"\t \t \t "<<r1.teamruns<<"-"<<r1.teamwickets<<" ("<<r1.teamovers<<")"<<endl;
        p<<'\n';
        p<<'\t'<<disbatsman1[0]<<"  "<<disbatruns1[0]<<" ("<<disbatballs1[0]<<")"<<"\t \t"<<disbowler2[0]<<"  "<<disbowlwickets2[0]<<"-"<<disbowlruns2[0]<<" ("<<setprecision(3)<<disbowlovers2[0]<<")"<<endl;
        p<<'\t'<<disbatsman1[1]<<"  "<<disbatruns1[1]<<" ("<<disbatballs1[1]<<")"<<"\t \t"<<disbowler2[1]<<"  "<<disbowlwickets2[1]<<"-"<<disbowlruns2[1]<<" ("<<setprecision(3)<<disbowlovers2[1]<<")"<<endl;
        p<<'\t'<<disbatsman1[2]<<"  "<<disbatruns1[2]<<" ("<<disbatballs1[2]<<")"<<"\t \t"<<disbowler2[2]<<"  "<<disbowlwickets2[2]<<"-"<<disbowlruns2[2]<<" ("<<setprecision(3)<<disbowlovers2[2]<<")"<<endl;
        p<<'\n'<<endl<<endl;
       if(r2.teamwickets==10)
        p<<'\t'<<"  "<<r2.team12<<"\t \t \t "<<r2.teamruns<<" ("<<r2.teamovers<<")"<<endl;
        else
        p<<'\t'<<"  "<<r2.team12<<"\t \t \t "<<r2.teamruns<<"-"<<r2.teamwickets<<" ("<<r2.teamovers<<")"<<endl;
        p<<'\n';
        p<<'\t'<<disbatsman2[0]<<"  "<<disbatruns2[0]<<" ("<<disbatballs2[0]<<")"<<"\t \t"<<disbowler1[0]<<"  "<<disbowlwickets1[0]<<"-"<<disbowlruns1[0]<<" ("<<setprecision(3)<<disbowlovers1[0]<<")"<<endl;
        p<<'\t'<<disbatsman2[1]<<"  "<<disbatruns2[1]<<" ("<<disbatballs2[1]<<")"<<"\t \t"<<disbowler1[1]<<"  "<<disbowlwickets1[1]<<"-"<<disbowlruns1[1]<<" ("<<setprecision(3)<<disbowlovers1[1]<<")"<<endl;
        p<<'\t'<<disbatsman2[2]<<"  "<<disbatruns2[2]<<" ("<<disbatballs2[2]<<")"<<"\t \t"<<disbowler1[2]<<"  "<<disbowlwickets1[2]<<"-"<<disbowlruns1[2]<<" ("<<setprecision(3)<<disbowlovers1[2]<<")"<<endl;
    }



    if((r1.choice1==2)||(r1.choice1==3))
    {
        p<<"\n \n \n "<<"\t \t \t "<<"MATCH SUMMARY"<<'\n'<<'\n'<<endl;
         if(r2.teamwickets==10)
        p<<'\t'<<"  "<<r2.team12<<"\t \t \t "<<r2.teamruns<<" ("<<r2.teamovers<<")"<<endl;
        else
        p<<'\t'<<"  "<<r2.team12<<"\t \t \t "<<r2.teamruns<<"-"<<r2.teamwickets<<" ("<<r2.teamovers<<")"<<endl;
        p<<'\n';
        p<<'\t'<<disbatsman2[0]<<"  "<<disbatruns2[0]<<" ("<<disbatballs2[0]<<")"<<"\t \t"<<disbowler1[0]<<"  "<<disbowlwickets1[0]<<"-"<<disbowlruns1[0]<<" ("<<setprecision(3)<<disbowlovers1[0]<<")"<<endl;
        p<<'\t'<<disbatsman2[1]<<"  "<<disbatruns2[1]<<" ("<<disbatballs2[1]<<")"<<"\t \t"<<disbowler1[1]<<"  "<<disbowlwickets1[1]<<"-"<<disbowlruns1[1]<<" ("<<setprecision(3)<<disbowlovers1[1]<<")"<<endl;
        p<<'\t'<<disbatsman2[2]<<"  "<<disbatruns2[2]<<" ("<<disbatballs2[2]<<")"<<"\t \t"<<disbowler1[2]<<"  "<<disbowlwickets1[2]<<"-"<<disbowlruns1[2]<<" ("<<setprecision(3)<<disbowlovers1[2]<<")"<<endl;
        p<<'\n'<<endl<<endl;
        if(r1.teamwickets==10)
        p<<'\t'<<"  "<<r1.team11<<"\t \t \t "<<r1.teamruns<<" ("<<r1.teamovers<<")"<<endl;
        else
        p<<'\t'<<"  "<<r1.team11<<"\t \t \t "<<r1.teamruns<<"-"<<r1.teamwickets<<" ("<<r1.teamovers<<")"<<endl;
        p<<'\n';
        p<<'\t'<<disbatsman1[0]<<"  "<<disbatruns1[0]<<" ("<<disbatballs1[0]<<")"<<"\t \t"<<disbowler2[0]<<"  "<<disbowlwickets2[0]<<"-"<<disbowlruns2[0]<<" ("<<setprecision(3)<<disbowlovers2[0]<<")"<<endl;
        p<<'\t'<<disbatsman1[1]<<"  "<<disbatruns1[1]<<" ("<<disbatballs1[1]<<")"<<"\t \t"<<disbowler2[1]<<"  "<<disbowlwickets2[1]<<"-"<<disbowlruns2[1]<<" ("<<setprecision(3)<<disbowlovers2[1]<<")"<<endl;
        p<<'\t'<<disbatsman1[2]<<"  "<<disbatruns1[2]<<" ("<<disbatballs1[2]<<")"<<"\t \t"<<disbowler2[2]<<"  "<<disbowlwickets2[2]<<"-"<<disbowlruns2[2]<<" ("<<setprecision(3)<<disbowlovers2[2]<<")"<<endl;
    }


return r1,r2;
}



  team teamres(team &r1,team &r2)
  {

      if((r1.choice1==1) | (r1.choice1==4))
      {
          if(r2.teamruns>r1.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<r1.team12<<" Won by "<<10-r2.teamwickets<<" Wickets!"<<endl;
          else if(r2.teamruns<r1.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<r1.team11<<" Won by "<<r1.teamruns-r2.teamruns<<" Runs!"<<endl;
            else if(r1.teamruns==r2.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<"Match Drawn!"<<endl;
      }

      if((r1.choice1==2) | (r1.choice1==3))
      {
          if(r2.teamruns<r1.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<r1.team11<<" Won by "<<10-r1.teamwickets<<" Wickets!"<<endl;
          else if(r2.teamruns>r1.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<r1.team12<<" Won by "<<r2.teamruns-r1.teamruns<<" Runs!"<<endl;
          else if(r1.teamruns==r2.teamruns)
            p<<'\n'<<'\t'<<'\t'<<'\t'<<'\n'<<"Match Drawn!"<<endl;
      }
      return r1,r2;
  }



int main()
{
    p.open("48(The Final)- England Vs New Zealand.txt",ios::out);
    if(!p)
        cout<<"Cannot open file"<<endl;
    team obj;
    obj.enterdata();
    obj.toss();

    team t1=obj;
    team t2=obj;



    if(obj.general::choice==1)
    {
    cout<<"\t \t Enter Batting detail of "<<obj.general::team1<<endl;
    t1.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team2<<endl;
    t2.bowling();

    team1cal(t1,t2);

    cout<<"\t \t Enter Batting detail of "<<obj.general::team2<<endl;
    t2.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team1<<endl;
    t1.bowling();

    team2cal(t2,t1);
    }



    if(obj.general::choice==4)
    {
        cout<<"\t \t Enter Batting detail of "<<obj.general::team1<<endl;
    t1.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team2<<endl;
    t2.bowling();

    team1cal(t1,t2);

    cout<<"\t \t Enter Batting detail of "<<obj.general::team2<<endl;
    t2.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team1<<endl;
    t1.bowling();

    team2cal(t2,t1);
    }

   if(obj.general::choice==2)
    {
    cout<<"\t \t Enter Batting detail of "<<obj.general::team2<<endl;
    t2.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team1<<endl;
    t1.bowling();
    team2cal(t2,t1);

    cout<<"\t \t Enter Batting detail of "<<obj.general::team1<<endl;
    t1.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team2<<endl;
    t2.bowling();
    team2cal(t1,t2);
    }


    if(obj.general::choice==3)
    {
       cout<<"\t \t Enter Batting detail of "<<obj.general::team2<<endl;
    t2.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team1<<endl;
    t1.bowling();
    team2cal(t2,t1);

    cout<<"\t \t Enter Batting detail of "<<obj.general::team1<<endl;
    t1.batting();
    cout<<"\t \t Enter Bowling detail of "<<obj.general::team2<<endl;
    t2.bowling();
    team2cal(t1,t2);
    }

    cout<<"\n \n \n \n \n \n \n \n \n "<<endl;




    //---------------------------------------------------------------------------------------------------------------------------------


    obj.display1();

    if(obj.general::choice==4)
    {
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Batting "<<endl;
    t1.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Bowling "<<endl;
    t2.displaybowl();
    p<<"\n \n \n";
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Batting "<<endl;
    t2.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Bowling "<<endl;
    t1.displaybowl();
    }


    if(obj.general::choice==1)
    {
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Batting "<<endl;
    t1.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Bowling "<<endl;
    t2.displaybowl();
    p<<"\n \n \n";
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Batting "<<endl;
    t2.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Bowling "<<endl;
    t1.displaybowl();
    }


     if(obj.general::choice==2)
    {
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Batting "<<endl;
    t2.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Bowling "<<endl;
    t1.displaybowl();
    p<<"\n \n \n";
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Batting "<<endl;
    t1.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Bowling "<<endl;
    t2.displaybowl();
    }

    if(obj.general::choice==3)
    {
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Batting "<<endl;
    t2.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Bowling "<<endl;
    t1.displaybowl();
    p<<"\n \n \n";
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team1<<" Batting "<<endl;
    t1.displaybat();
    p<<'\n'<<'\t'<<'\t'<<'\t'<<obj.general::team2<<" Bowling "<<endl;
    t2.displaybowl();
    }
     teamsort(t1,t2);
     p<<"\n \n \n \n \t"<<endl;
     teamres(t1,t2);
    p.close();
    getch();
    return 0;
}
