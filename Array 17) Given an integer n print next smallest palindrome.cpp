#include<bits/stdc++.h>
using namespace std;

/**there are three type of  inputs
    1) all 9's  9 9 9
    2) input is palindrome 1 2 2 1
    3) input is not palindrome 1 2 3 4

**/

void generate_next(vector<int> num)
{
    int n=num.size();
    int mid =n/2;
    /// to check if we can copy left side of number to right side
    bool left_smaller =false;
    int i= mid-1; ///end of left side
    int j = (n%2) ? mid+1:mid; ///beginning of right side

    ///initially ignore middle same digits
    while(i>=0 && num[i]==num[j])
    {
        i--;
        j++;
    }

    ///find if middle element is needed to be incremented or not
    if(i<0 || num[i] < num[j])
    {
        left_smaller=true;
    }
    ///copy left digits to right
    while(i>=0)
    {
        num[j]=num[i];
        j++;
        i--;
    }
    ///to handle the case where middle element is needed to be incremented or not

    if(left_smaller == true)
    {
        int carry =1;
        i =mid-1;
        if(n%2 ==1)
        {
            num[mid]+=carry;
            carry =num[mid]/10;
            num[mid]%=10;
            j=mid+1;
        }
        else
        {
            j=mid;
        }

        while(i>=0)
        {
            num[i]+=carry;
            carry = num[i]/10;
            num[i]%=10;
            num[j++]=num[i--];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<num[i];
    }

}

void print_next_pal(vector<int> v)
{
    int n=v.size();
    ///input type 1st
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(v[i] !=9)
        {
            flag=1;
            break;
        }
    }
    /// all digits are 9
    if(flag ==0)
    {
        ///print n+1 digits with 1 at both ends and 0 as middle all digits
        cout<<"1";
        for(int i=1;i<n;i++)
        {
            cout<<"0";
        }
        cout<<"1";
    }
    else
    {
        /// for input type 2 and type 3
        generate_next(v);
    }
}



void next(int n)
{
    /// we have to extract digits to an array;
    vector<int> v;
    while(n%10 !=0)
    {
        int k=n%10;
        n=n/10;
        v.push_back(k);
    }
    reverse(v.begin(),v.end());
    print_next_pal(v);
}

int main()
{
    int n;
    cin>>n;
    next(n);


}
