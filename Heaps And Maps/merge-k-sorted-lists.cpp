// https://www.interviewbit.com/problems/merge-k-sorted-lists/

// Divide and conquer
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    
    ListNode dummy(0);
    ListNode* ans = &dummy;
    
    while(l1 && l2){
        if(l1 -> val < l2 -> val){
            ans -> next = l1;
            l1 = l1 -> next;
        }
        else{
            ans -> next = l2;
            l2 = l2 -> next;
        }
        ans = ans -> next;
    }
    
    ans -> next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    while(n > 1){
        for(int i = 0; i < n / 2; ++i)
            A[i] = mergeTwoLists(A[i], A[n - 1 - i]);
        n = (n + 1) / 2;
    }
    return A.front();
}

// Priority Queue
struct compareNode{
    bool operator()(ListNode* const &p1, ListNode* const &p2){
        return p1 -> val > p2 -> val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, compareNode> q;
    for(int i = 0; i < A.size(); ++i)
        if(A[i])
            q.push(A[i]);
            
    ListNode dummy(0);
    ListNode* ans = &dummy;
    
    while(!q.empty()){
        ans -> next = q.top();
        q.pop();
        ans = ans -> next;
        
        if(ans -> next)
            q.push(ans -> next);
    }
    
    return dummy.next;
}
