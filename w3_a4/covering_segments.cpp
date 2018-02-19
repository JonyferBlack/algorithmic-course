#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	//write your code here

	std::sort(begin(segments), end(segments), [](const auto& a, const auto& b) {
		return a.start < b.start;
	});

	size_t n = segments.size();
	for (size_t i = 1; i < n; ++i) {
		auto& current = segments[i - 1];
		while ((segments[i].start <= current.end) && (i < n)) {
			if ((segments[i].end < current.end)){
				current = segments[i];
			}
			++i;
		}
		points.push_back(current.end);
	}

	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
