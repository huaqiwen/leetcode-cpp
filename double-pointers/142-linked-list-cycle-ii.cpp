// ID: 142
// Title: Linked List Cycle II
// Type: Two Pointers
// Difficulty: Medium
// URL: https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *detectCycle(ListNode *head);

int main() {
    ListNode n1 = ListNode(3);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(0);
    ListNode n4 = ListNode(-4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;

    ListNode* start = detectCycle(&n1);
    cout << ((start == nullptr) ? "NULL" : to_string(start->val)) << endl;

    return 0;
}


/**
 * @brief Detects and returns the start of a cycle in a LL using 
 * [Floyd's Tortoise and Hare algorithm](https://en.wikipedia.org/wiki/Cycle_detection)
 * 
 * @param head the head of the LL
 * @return ListNode* the start of a cycle in LL
 */
ListNode* detectCycle(ListNode *head) {
    ListNode *tortoise = head, *hare = head;

    // check whether a cycle exists
    do {
        // hare reaches the end of the LL, no cycle
        if (!hare || !hare->next) return nullptr;

        // move tortoise and hare
        tortoise = tortoise->next;
        hare = hare->next->next;
    } while (hare != tortoise);

    // cycle exists, find start of cycle
    hare = head;
    while (hare != tortoise) {
        tortoise = tortoise->next;
        hare = hare->next;
    }
    
    return hare;
}
