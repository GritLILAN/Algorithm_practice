#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* head = new ListNode();
        ListNode* p = head;
        bool first = true;

        while(p1 || p2){
            if(!p2 || (p1 && p1->val < p2->val)) {  // 修复了缺少的括号
                if(first){
                    head = p = p1;  // 修改了初始指针处理
                    p1 = p1->next; 
                    first = false;
                } else {
                    p->next = p1;
                    p = p->next;
                    p1 = p1->next;
                }
            }
            else{
                if(first){
                    head = p = p2;  // 修改了初始指针处理
                    p2 = p2->next; 
                    first = false;
                } else {
                    p->next = p2;
                    p = p->next;
                    p2 = p2->next;
                }
            }
        }
        return head;
    }
};

// 辅助函数：从数组创建链表
ListNode* createList(int arr[], int n) {
    if(n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // 测试用例1
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    ListNode* merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);
    
    // 测试用例2：空链表
    int arr3[] = {};
    int arr4[] = {0};
    ListNode* list3 = createList(arr3, 0);
    ListNode* list4 = createList(arr4, 1);
    
    cout << "\nList 3: ";
    printList(list3);
    cout << "List 4: ";
    printList(list4);
    
    ListNode* merged2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged List: ";
    printList(merged2);
    
    return 0;
}
