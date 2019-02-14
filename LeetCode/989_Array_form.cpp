#include <iostream>
#include <vector>
using namespace std;
#include <math.h>

// its a typical error example
/* class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        unsigned long long int sum = 0, int_A = 0;

        // turn A -> int_A
        int len = A.size();
        for(int i = 0; i < len; i++ )
        {
            int_A += pow(10, (len - i - 1) ) * A[i] ;
        }

        // int_A + K = sum
        sum = int_A + K;

        if(sum==0) 
        { 
            result.push_back(0);
            return result;
        }
        else{
            // turn sum -> vector<int>
            while( 0 < sum )
            {
                int dec = 0;
                dec = sum % 10;
                result.insert( result.begin() , dec );
                sum /= 10;
            }
            return result;
        }
    }
}; */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        // convert K to vector<int>
        vector<int> B;
        if(K == 0)
            B.push_back(0);
        else
        {
            while(0 < K)
            {
                int dec = 0;
                dec = K % 10;
                B.insert( B.begin(), dec );
                K /= 10;
            }
        }

        // define rank r1, r2; and sth else
        bool carryFlag = false;
        int r1 = 0, r2 = 0;
        r1 = A.size() > B.size() ? A.size() : B.size();
        r2 = A.size() > B.size() ? B.size() : A.size();

        // scan to add element in 2 vector<int>
        vector<int> result;
        int dec = 0;
        for( int i = 0; i < r1; i++ )
        {
            if( r2-1 < i )
            {
                if( A.size() > B.size() )
                { 
                    if(carryFlag == true)
                        dec = A[A.size() - 1 - i] + 1;
                    else
                        dec = A[A.size() - 1 - i];
                    
                    if(dec >= 10) 
                    {
                        dec %= 10;
                        result.insert(result.begin(), dec);
                        carryFlag = true;
                    }
                    else
                    {
                        result.insert(result.begin(), dec);
                        carryFlag = false;
                    }
                }
                else
                { 
                    if(carryFlag == true)
                        dec = B[B.size() - 1 - i] + 1;
                    else
                        dec = B[B.size() - 1 - i];

                    if(dec >= 10) 
                    {
                        dec %= 10;
                        result.insert(result.begin(), dec);
                        carryFlag = true;
                    }
                    else
                    {
                        result.insert(result.begin(), dec);
                        carryFlag = false;
                    }
                }            

            }

            else
            {
                if(carryFlag == true)
                    dec = A[A.size() - 1 - i] + B[B.size() - 1 - i] + 1;
                else
                    dec = A[A.size() - 1 - i] + B[B.size() - 1 - i];

                if(dec >= 10) 
                {
                    dec %= 10;
                    result.insert(result.begin(), dec);
                    carryFlag = true;
                }
                else
                {
                    result.insert(result.begin(), dec);
                    carryFlag = false;
                }              
            }
            
        }

        // 退出的时候检查是否需要进位扩展位数
        if( carryFlag == true ) result.insert( result.begin(), 1 );

        return result;
    }
};

class Solution_Ref {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        //
        int len = A.size();
        int i = 0;
        int tmp = K;
        //
        vector<int> result;
        while( i < len || tmp > 0 )
        {
            if(i < len) tmp += A[len - i - 1];
            result.insert(result.begin(), tmp%10);
            tmp /= 10;
            i++;
        }
        return result;
    }
};

int main( int argc, char** argv )
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(9);
    arr.push_back(9);

    int K = 1111;
    Solution_Ref solution;
    vector<int> result;
    result = solution.addToArrayForm( arr, K );
    for( auto& ele:result )
    {
        cout << ele << " ";
    }

    return 0;
}