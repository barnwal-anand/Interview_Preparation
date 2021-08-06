// LeetCode - 223 Rectangle Area
//iven the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

class RangeOverlap {
private:
    int startPoint;
    int length;

public:
    RangeOverlap() {
        startPoint = 0;
        length = 0;
    }

    RangeOverlap(int p, int l) {
        startPoint = p;
        length = l;
    }

    int getStartPoint() {
        return startPoint;
    }

    int getLength() {
        return length;
    }
};

class Solution {
public:
    RangeOverlap getRangeOverlap(int start1, int end1, int start2, int end2) {
        int maxStart = max(start1, start2);
        int minEnd = min(end1, end2);

        if (maxStart >= minEnd) {
            return RangeOverlap();
        }

        int overlapLength = minEnd - maxStart;

        return RangeOverlap(maxStart, overlapLength);
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        RangeOverlap xOverlap = getRangeOverlap(A, C, E, G);
        RangeOverlap yOverlap = getRangeOverlap(B, D, F, H);

        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        int overlapArea = xOverlap.getLength() * yOverlap.getLength();

        return area1 + area2 - overlapArea;
    }
};
