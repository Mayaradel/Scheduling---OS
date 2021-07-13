#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FIFO (int requests[], int size, int head)
{
    int i,j;
    float sum =0;
    int distance =0;
    int currentPosition;
    float average = 0.0;

    cout<<"The Sequence is\n";
    cout<<"----------------------\n";
    for (i=0 ; i< size; i++)
    {
        cout<<" " <<requests[i];
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"----------------------\n";

    for (j=0 ; j<size ; j++)
    {
        currentPosition =requests[j];

        distance = abs(head-currentPosition);
        sum = sum + distance;
        head = currentPosition;

    }

    cout<<"Total head movement\n";
    cout<< sum;
    cout<<"\n";
    cout<<"----------------------\n";
    cout<<"Average head movement\n";
    average = sum/size;
    cout<< average;
    cout<<"\n";
    cout<<"----------------------\n";

}

void SCAN(int arr[], int size, int head,int disk_size)
{
    int distance;
    int current_position;
    vector <int> decreasing ;
    vector <int> increasing;
    vector <int> mySequence;
    int direction;
    float sum = 0.0;
    float average = 0.0;

    cout << "Enter the direction you want \n";
    cout<<"----------------------\n";
    cout <<"1-for decreasing\n2-for increasing\n";
    cin>>direction;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            decreasing.push_back(arr[i]);
        if (arr[i] > head)
            increasing.push_back(arr[i]);
    }

    // sorting decreasing and increasing vectors
    std::sort(decreasing.begin(), decreasing.end());
    std::sort(increasing.begin(), increasing.end());


    int run = 2;
    while (run--)
    {
        if (direction ==1 )
        {
            for (int i = decreasing.size() - 1 ; i >= 0 ;  i--)
            {
                current_position = decreasing[i];
                mySequence.push_back(current_position);

                distance = abs(head-current_position);
                sum = sum + distance;
                head = current_position;
            }
            direction = 2;
        }

        else if (direction == 2)
        {
            for (int i = 0; i < increasing.size(); i++)
            {
                current_position = increasing[i];

                mySequence.push_back(current_position);

                distance = abs(head-current_position);
                sum = sum + distance;
                head = current_position;
            }
            direction = 1;
        }
    }

    cout<<"----------------------\n";
    cout << "The resultant sequence is" << endl;
    cout<<"----------------------\n";
    for (int i = 0; i < mySequence.size(); i++)
    {
        cout << mySequence[i] << endl;
    }
    cout<<"----------------------\n";
    cout << "Total number of seek operations\n"<< sum << endl;
    cout<<"----------------------\n";

    average = sum/size;
    cout <<"the average of the algorithms\n";
    cout<<"----------------------\n";
    cout<<average;

}


void CSCAN(int arr[], int head, int size)
{
    float sum =0.0 ;
    int distance = 0;
    int current_position;
    vector<int> left, right;
    vector<int> mySequence;
    int direction;
    float average =0.0 ;



    cout<< "Enter the direction you want \n";
    cout<<"----------------------\n";
    cout<<"1 for decreasing\n2 for increasing\n";
    cout<<"----------------------\n";
    cin>>direction;



    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int traverse[size];



    switch (direction)
    {

    case 1:
    {
        for (int i = left.size() - 1 ; i >= 0 ;  i--)
        {
            current_position = left[i];
            mySequence.push_back(current_position);

            distance = abs(head-current_position);
            traverse[i]=distance;
            sum = sum + distance;
            head = current_position;


        }
        for (int i =right.size()-1 ; i>= 0 ; i--)
        {
            current_position = right[i];
            mySequence.push_back(current_position);
            distance = abs(head-current_position);
            traverse[i] = distance;
            sum = sum + distance;
            head = current_position;
        }

        cout << "The resultant sequence is" << endl;
        for (int i = 0; i < mySequence.size(); i++)
        {
            cout << mySequence[i] << endl;
        }

        cout << "Total number of seek operations\n"<< sum << endl;
        cout<<"----------------------\n";

        average = sum/size;
        cout <<"the average of the algorithms\n";
        cout<<"----------------------\n";
        cout<<average;
        break;
    }



    case 2 :
    {
        //increasing
        for (int i = 0; i < right.size(); i++)
        {
            current_position = right[i];
            mySequence.push_back(current_position);

            distance = abs(current_position-head);
            sum = sum + distance;
            head = current_position;
        }

        for (int i = 0; i < left.size(); i++)
        {
            current_position = left[i];

            mySequence.push_back(current_position);

            distance = abs(current_position-head);
            sum = sum + distance;
            //cout<<"head = "<<head<<" - current pos = "<<current_position<<" - Distance = "<<distance<<endl;
            head = current_position;
        }
        cout << "Seek Sequence is" << endl;
        for (int i = 0; i < mySequence.size(); i++)
        {
            cout << mySequence[i] << endl;
        }
    }
    cout << "Total number of seek operations\n"<< sum << endl;
    cout<<"----------------------\n";

    average = sum/size;
    cout <<"the average of the algorithms\n";
    cout<<"----------------------\n";
    cout<<average;
    break;

    }
}

int main()
{

//attributes

    int disk_size;
    int requestsNum;
    int head;

    int i;
    int x=0;

////User input

    cout<<"Enter the disk size\n";
    cin>>disk_size;
    cout<<"----------------------\n";
//

    cout<<"Enter the number of requests\n";
    cin>>requestsNum;
    cout<<"----------------------\n";

    int requests[requestsNum] ;

    cout<<"Enter the head\n";
    cin>>head;
    cout<<"----------------------\n";

    cout<<"Enter the requests\n";
    for (i=0; i<requestsNum; i++)
    {
        cin>>requests[i];
    }
    cout<<"----------------------\n";


    for(i = 0 ; i <requestsNum ; i++)
    {
        if(requests[i]>disk_size)
        {
            cout<<"Error, Unknown position "<<requests[i]<<"\n";
            return 0;
        }
    }

    //Scheduling Method

    cout<<"Enter the scheduling method you want\n";
    cout<<"----------------------\n";
    cout<< "1- FIFO\n2- SCAN\n3- CSCAN\n";
    cout<<"----------------------\n";
    cin>>x;
    cout<<"----------------------\n";

    if (x==1)
    {
        FIFO(requests,requestsNum,head);
    }
    if (x==2)
    {
        SCAN(requests,requestsNum,head,disk_size);
    }
    if (x==3)
    {
        CSCAN(requests,head,requestsNum);
    }

    return 0;
}

