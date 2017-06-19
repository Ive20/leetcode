#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> used = vector<int>();
		int i=0;
		for(vector<int>::iterator iter=nums.begin();iter!=nums.end();iter++){
			int j=i;
			for(vector<int>::iterator iter2 =iter+1 ;iter2!=nums.end();iter2++){
				j++;
				if(*iter+*iter2==target){
					used.push_back(i);
					used.push_back(j);
					return used;
					}		
				}
			i++;
			}
			return used;
		}
};