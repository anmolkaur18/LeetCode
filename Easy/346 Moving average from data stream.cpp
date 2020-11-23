
class movingAverage{
private:
     queue<int> q;
     int maxSize;
     double sum;

     /* initialize your data structure here*/\
public:
    void movingAverage(int size){
        maxSize = size;
        sum = 0.0;
    }

    double next(int val){
    if(q.size() == maxSize){
        sum -= q.pop();  // we pop from queue and also subtract from sum
    }
        q.push(val);
        sum += val;
        return sum / q.size();
    }

};


/*
problem:
Design a class, MovingAverage, which contains a method, next that is responsible for returning the moving average from a stream of integers.
Note: a moving average is the average of a subset of data at a given point in time.

Ex: Given the following series of events...

// i.e. the moving average has a capacity of 3.
MovingAverage movingAverage = new MovingAverage(3);
m.next(3) returns 3 because (3 / 1) = 3
m.next(5) returns 4 because (3 + 5) / 2 = 4
m.next(7) = returns 5 because (3 + 5 + 7) / 3 = 5
m.next(6) = returns 6 because (5 + 7 + 6) / 3 = 6


MovingAverage class definition:

public class MovingAverage {
    // TODO: declare any instance variables you require.
 * Initializes a MovingAverage with a
 * capacity of `size`.
 *

public MovingAverage(int size) {
  // TODO: initialize your MovingAverage.
}

 * Adds `val` to the stream of numbers
 * and returns the current average of the numbers.
 *
public double next(int val) {
   // TODO: implement this method.
}

}
*/

