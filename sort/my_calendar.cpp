class MyCalendar {
public:
  
  struct interval{
    int start, finish;
    interval(int x, int y): start(x), finish(y){}
  }

  vector<interval *> int_list;

  MyCalendar() {}
    
  bool book(int start, int end) {
    if(int_list.empty()){
      int_list.emplace_back(new interval(start, end));
      return true;
    }
    for(auto &i: int_list){
      if(i -> finish > start && i -> finish <= end) 
        return false;
    }
    int_list.emplace_back(new interval(start, end));
    return true;
  }

};