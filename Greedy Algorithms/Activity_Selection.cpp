#include<bits/stdc++.h>

using namespace std;


struct job{
	int number;
	int start;
	int finish;
};

void maximum_activity(job arr[], int n){
	int current =0; int next;
	cout<<arr[current].number << " ";
	for(next=1;next<n;next++){
		if(arr[current].finish <= arr[next].start){
			current=next;
			cout<< arr[current].number << " ";
		}
	}
}

bool compare (job a, job b){
	return a.finish < b.finish;
}

/*
5
1 3
2 3
7 9
5 7
8 10

1 3 4
*/
int main(){
	int n;
	cin>>n;

	struct job activities [n];

	for(int i=0; i<n; i++){
		activities[i].number = i+1;
		cin>> activities[i].start;
		cin>> activities[i].finish;
	}

	sort(activities,activities+n, compare);
	maximum_activity(activities,n);
	return 0;
}
