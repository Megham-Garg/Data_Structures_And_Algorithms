bool compareArea(vector<int> box1, vector<int> box2) {
    return box1[0]*box1[1] > box2[0]*box2[1];
}

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<vector<int>> boxes;
    for(int i = 0; i < n; i++){
        int a = length[i];
        int b = width[i];
        int c = height[i];
        vector<int> box(3);
        box[0] = max(a,b); box[1] = min(a,b); box[2] = c;
        boxes.push_back(box);
        box[0] = max(c,b); box[1] = min(c,b); box[2] = a;
        boxes.push_back(box);
        box[0] = max(a,c); box[1] = min(a,c); box[2] = b;
        boxes.push_back(box);
    }
    sort(boxes.begin(), boxes.end(), compareArea);
    int ht[3*n], mht = boxes[0][2];
    for(int i = 0; i < 3*n; i++) ht[i] = boxes[i][2];
    for(int i = 1; i < 3*n; i++){
        for(int j = 0; j < i; j++){
            if(boxes[j][0] > boxes[i][0]&&boxes[j][1] > boxes[i][1])
            ht[i] = max(ht[j] + boxes[i][2], ht[i]);
        }
        mht = max(mht, ht[i]);
    }
    return mht;
}
