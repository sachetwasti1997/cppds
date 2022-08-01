class Solution {
public:
    Node* flatten(Node* head) {
      Node *h{head}, *ch{nullptr}, *nx{nullptr};
      while(h){
        ch = nullptr, nx = h -> next;
        if(h->child){
          ch = h -> child;
          h -> next = ch;
          ch -> prev = h;
          h -> child = nullptr;
          while(ch -> next){
            ch = ch -> next;
          }
          ch -> next = nx;
          if(nx)nx -> prev = ch;
        }
        h = h -> next;
      }
      delete h;
      delete ch;
      delete nx;
      return head;
    }
};