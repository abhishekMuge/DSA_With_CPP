class FoodRatings {
    // Comparator: returns true if a has lower priority than b
struct Cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) return a.first < b.first;   // smaller rating -> lower priority
        return a.second > b.second;                        // lexicographically larger name -> lower priority
    }
};
private:
    unordered_map<string, string> foodToCuisine; // food -> cuisine
    unordered_map<string, int> foodToRating;     // food -> current rating
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Cmp>> cuisinePQ;
    // cuisine -> max-heap of (rating, food)
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            const string &food = foods[i];
            const string &cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisinePQ[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        // Update current rating map
        foodToRating[food] = newRating;
        // Push new pair into the cuisine heap (lazy deletion of old pair)
        cuisinePQ[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisinePQ[cuisine];
        // Pop stale entries until the top matches current rating
        while (!pq.empty()) {
            auto top = pq.top();
            int rating = top.first;
            const string &food = top.second;
            if (foodToRating[food] == rating) {
                return food;
            }
            pq.pop(); // stale entry
        }
        return ""; // should not happen under problem constraints
    }
};