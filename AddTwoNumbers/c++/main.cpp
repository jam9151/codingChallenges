#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(int x);
void testValue(ListNode *head);
class Solution{
    
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            
            if(l1==NULL && l2==NULL) return l2;

            else if(l1==NULL) return l2;

            else if(l2==NULL) return l1;

            int sum =l1->val+l2->val;
            
            //taking the unit digit only in consideration 
            
            ListNode* newNode = new ListNode(sum%10);
            
            newNode->next=addTwoNumbers(l1->next,l2->next);
            
            //if the sum has carry it will be not more than 1 so 
            //add a new node and add the next value of the linkedlist with the carry one 
            
            if(sum>=10){
                newNode->next=addTwoNumbers(newNode->next,new ListNode(1));
            }
            
            return newNode;
            
        }
};


int main(){
    

    Solution *solution = new Solution();
    vector<std::string> = new
    ListNode *ll1 = createLinkedList(243);
    testValue(ll1);

    ListNode *ll2 = createLinkedList(564);
    // testValue(ll2);
    
    ListNode *head = solution->addTwoNumbers(ll1,ll2);
    ListNode *cpHead = head;
    
    while(cpHead!=NULL){
        //std::cout << cpHead->val;
        cpHead = cpHead->next;

    }

}

ListNode *createLinkedList(int x){
    
    std::string strLinkedListValues = std::to_string(x);
    
    ListNode *head = new ListNode();

    ListNode *workingNode = head;


    for(int i = 0; i < strLinkedListValues.length(); i++){
        
        //int charToInt = strLinkedListValues.at(i) - '0';
        
        int charToInt = strLinkedListValues.at(strLinkedListValues.length() - i - 1) - '0';
        
        workingNode->val = charToInt;
        
        if(i != strLinkedListValues.length() - 1){
            
            workingNode->next = new ListNode();
            
            workingNode = workingNode->next;
        } 
        
    }
    return head;

}


void testValue(ListNode *head){
    
    
    ListNode *cpHead = head;

    std::vector<int> values;

    while(cpHead != NULL){

        //std::cout << cpHead->val;
        
        values.push_back(cpHead->val);
        
        cpHead = cpHead->next;
        
    }

    for(auto i: values){
        std::cout << i;   
    }


}