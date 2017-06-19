#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> v1;
		vector<int> v2;
		vector<int> v3;
		while(l1!=NULL){
			v1.insert(v1.begin(),l1->val);
			l1= l1->next;
		}
		while(l2!=NULL){
			v2.insert(v2.begin(),l2->val);
			l2= l2->next;
		}
		ListNode * first;
		ListNode * l4 = new ListNode(0);
		int length =0;
		int v1s =v1.size();
		int v2s =v2.size();
		if(v1s>=v2s){
			length =v1.size();
			for(int i=0;i<v1s-v2s;i++){
				v2.insert(v2.begin(),0);
			}
		}else{
			length =v2.size();
			for(int i=0;i<v2s-v1s;i++){
				v1.insert(v1.begin(),0);
			}
		}
		bool add =false;
		for(int i=length-1;i>=0;i--){
			l4->next = new ListNode(0);
			l4 =l4->next;
			if(add){
				l4->val = v1[i]+v2[i]+1; 
			}else{
				l4->val = v1[i]+v2[i]; 
			}
			if(l4->val>=10){
				l4->val=l4->val%10;
					add=true;
				}else{
					add=false;
			}
			if(i==length-1){
				first=l4;
			}
		}
		if(add ==true){
			l4->next = new ListNode(0);
			l4->next->val=1;
		}
		return first;
    }
};