#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1){
            return 1;
        }
		int length =0;
		string used ="";
		string leftused ="";
		string rightused ="";
		int mid=s.length()/2;
		int leftmax=mid;
		int rightmax=mid;
		int i=mid;
		int j=mid;
		int midlength = 1;
		int leftlength =lengthOfLongestSubstring(s.substr(0,mid));
		int rightlength =lengthOfLongestSubstring(s.substr(mid-1,mid+1));
        bool needstop= false;
		while((i>=0||j<=s.length()-1)&&!needstop){
			if(i>=0&&!needstop){
				i=i-1;
				char left = s[i];
				if(rightused.find(left)==-1){
					if(leftused.find(left)!=-1){
						leftmax =i+1;
						i= -1;
					}else{
						used+=left;
						leftused+=left;
						midlength++;
					}
				}else{
                 int templeftmidlength=midlength;
                   string tempused = used;
                   while(i>=0&&!needstop){
                   i=i-1;
				    char left = s[i];      
                     if(tempused.find(left)!=-1){	
                        needstop= true;
					}else{
						tempused+=left;
						templeftmidlength++;
					}   
                   } 
                   int temprightmidlength=midlength;
                   tempused = used;
                   while(j<=s.length()-1&&!needstop){
			        char right = s[j];
				    if(rightused.find(right)!=-1){
                     needstop= true;	
				    }else{
					    tempused+=right;
					    tempused+=right;
					    temprightmidlength++;
				    }
                    j=j+1;
			        }
                    midlength = max(temprightmidlength,templeftmidlength-1);
				}
			}

			if(j<=s.length()-1&&!needstop){
			    char right = s[j];
				if(leftused.find(right)!=-1){
					if(rightused.find(right)!=-1){
						leftmax =i+1;
						j= s.length();
					}else{
						used+=right;
						rightused+=right;
						midlength++;
					}
				}else{
                  int templeftmidlength=midlength;
                   string tempused = used;
                   while(i>=0&&!needstop){
                   i=i-1;
				    char left = s[i];      
                     if(tempused.find(left)!=-1){	
                        needstop= true;
					}else{
						tempused+=left;
						templeftmidlength++;
					}   
                   } 
                   int temprightmidlength=midlength;
                   tempused = used;
                   while(j<=s.length()-1&&!needstop){
			        char right = s[j];
				    if(rightused.find(right)!=-1){
                     needstop= true;	
				    }else{
					    tempused+=right;
					    tempused+=right;
					    temprightmidlength++;
				    }
                    j=j+1;
			        }
                    midlength = max(temprightmidlength-1,templeftmidlength);
				  }
                }
                j=j+1;
		}
			return max(max(midlength,leftlength),rightlength);
    }
};


