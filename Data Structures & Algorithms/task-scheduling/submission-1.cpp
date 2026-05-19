class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        priority_queue<int> maxheap;
        for(int c : freq){
            if(c > 0) maxheap.push(c);
        }
        queue<pair<int, int>> cooldown_q; //{how many times left to do, next available time}
        int time = 0;

        while(!maxheap.empty() || !cooldown_q.empty()){
            time++;
            if(!maxheap.empty()){
                int most_freq = maxheap.top();
                maxheap.pop();
                if(most_freq > 1){
                    cooldown_q.push({most_freq-1, time+n});
                }
            }else{
                time = cooldown_q.front().second;
            }

            if(!cooldown_q.empty() && cooldown_q.front().second==time){
                maxheap.push(cooldown_q.front().first);
                cooldown_q.pop();
            }
        }
        
        return time;
    }
};
