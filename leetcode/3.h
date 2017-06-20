#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1){
            return s.length();
        }
		
		string used ="";
		string leftused ="";
		string rightused ="";
		int mid=s.length()/2;
		int leftmax=mid;
		int rightmax=mid;
		int i=mid-1;
		int j=mid;
		int midlength = 0;
        bool needstop= false;
		bool leftstop= false;
		bool rightstop= false;
	    int leftmaxtemplength  = 0;
	    int rightmaxtemplength  = 0;
		int rightleftmaxtemplength = 0;
		int leftrightmaxtemplength = 0;
		while(((i>=0&&!leftstop)||(j<=s.length()-1&&!rightstop))&&!needstop){
			if(i>=0&&!needstop&&!leftstop){
				char left = s[i];
				if(rightused.find(left)==-1){
					if(leftused.find(left)!=-1){
						leftstop=true;
						leftmaxtemplength = lengthOfLongestSubstring(s.substr(i+1,s.length()-i-1));
						i=i+1;
					}else{
						used+=left;
						leftused+=left;
						midlength++;
					}
				}else{
                 int templeftmidlength=midlength;
				 int tempj =j-1;	  
                   string tempused = used;
				   string templeftused= leftused;
                   while(i>=1&&!needstop&&!leftstop){
					    i=i-1;
				    char left = s[i];      
                     if(templeftused.find(left)!=-1){	
                        leftstop=true;
					}else{
						templeftused+=left;
						tempused+=left;
						templeftmidlength++;
					}  
                   } 
                   int temprightmidlength=midlength;
                   tempused = used;
                   while(j<=s.length()-1&&!needstop){
			        char right = s[j];
				    if(tempused.find(right)!=-1){
                     needstop= true;	
				    }else{
					    tempused+=right;
						rightused+=right;
					    temprightmidlength++;
				    }
                    j=j+1;
			        }
				   int rightfind = s.substr(mid,mid+1).find_first_of(left);
				   int leftfix = tempj-mid - rightfind;
                    midlength = max(midlength,max(rightmaxtemplength,max(temprightmidlength,templeftmidlength-leftfix)));
				}
				i=i-1;
			}

			if(j<=s.length()-1&&!needstop&&!rightstop){
			    char right = s[j];
				if(leftused.find(right)==-1){
					if(rightused.find(right)!=-1){
						rightstop =true;
						rightmaxtemplength = lengthOfLongestSubstring(s.substr(0,j-1));
						j=j-1;
					}else{
						used+=right;
						rightused+=right;
						midlength++;
					}
				}else{
					 int tempi=i+1;
                  int templeftmidlength=midlength;				
                   string tempused = used;
                   while(i>=0&&!needstop){      
				    char left = s[i];      
                     if(tempused.find(left)!=-1){	
                       i=0;
					}else{
						tempused+=left;
						templeftmidlength++;
					}  
					 i=i-1;
                   } 
                   int temprightmidlength=midlength;
                   tempused = used;
				 
                   while(j<=s.length()-2&&!needstop){
					 j=j+1;     
			        char right = s[j];
				    if(tempused.find(right)!=-1){
                     needstop= true;	
				    }else{
					    tempused+=right;
						temprightmidlength++;
				    }
			        }
				   int leftfind = s.substr(0,mid).find_last_of(right);
				   int rightfix = leftfind-tempi;
                    midlength = max(midlength,max(leftmaxtemplength,max(temprightmidlength-rightfix,templeftmidlength)));
                  
				  }
				j=j+1;
                }
                
		}
		int leftlength = lengthOfLongestSubstring(s.substr(0,mid));
		int rightlength =lengthOfLongestSubstring(s.substr(mid,mid+1));
			return max(max(midlength,leftlength),rightlength);
    }
};


