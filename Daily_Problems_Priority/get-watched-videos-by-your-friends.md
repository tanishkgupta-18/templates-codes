**Problem Link**: [get-watched-videos-by-your-friends](https://leetcode.com/problems/get-watched-videos-by-your-friends)

```
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        map<string, int> freq;

        queue<pair<int, int>> q;
        visited[id] = true;
        q.push({id, 0});

        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(dist == level){
                for(string& video : watchedVideos[node]){
                    freq[video]++;
                }

                continue;
            }
            for(auto neighbor : friends[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, dist+1});
                }
            }
        }

        vector<pair<int, string>> sortedVideos;
        for (const auto& [video, count] : freq) {
            sortedVideos.emplace_back(count, video);
        }

        sort(sortedVideos.begin(), sortedVideos.end());

        vector<string> result;
        for (const auto& [count, video] : sortedVideos) {
            result.push_back(video);
        }

        return result;
    }
};
```