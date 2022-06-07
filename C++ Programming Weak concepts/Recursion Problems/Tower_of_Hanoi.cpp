#include <bits/stdc++.h>
using namespace std;
void TowerOfHanoi(int no_of_disks, string source,string helper, string destination)
{
    if (no_of_disks==1)
    {
        cout<<"Transferring the disk no "<<no_of_disks<<" from "<<source<<" to "<<destination<<endl;
        return;
    }

    // first step to transfer the (n-1) disk to the helper tower via the destination tower from the source tower.
    TowerOfHanoi(no_of_disks-1, source, destination, helper);
    cout<<"Transferring the disk no "<<no_of_disks<<" from "<<source<<" to "<<destination<<endl;
    // second step is to transfer the no of disk from the helper tower to the destination tower via the source tower.
    TowerOfHanoi(no_of_disks-1, helper, source, destination);

}
int main()
{
    TowerOfHanoi(2, "Source", "helper", "Destination");
    return 0;
}