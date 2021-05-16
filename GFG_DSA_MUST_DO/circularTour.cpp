
// int tour(petrolPump p[],int n){
//     queue<petrolPump> q;
//     for(int i = 0; i < n; i++) q.push(p[i]);
//     int xOp = 0; int scanned = 0; int extra = 0;
//     while(xOp < n && scanned < n){
//         if(q.front().petrol+extra < q.front().distance){
//             scanned += 1;
//             if(xOp==0 || q.front().petrol < q.front().distance){
//                 q.push(q.front());
//                 q.pop();
//             }
//             xOp = 0;
//             extra = 0;
//         }
//         else{
//             xOp++;
//             extra += q.front().petrol - q.front().distance;
//             q.push(q.front());
//             q.pop();
//         }
//     }
//     for(int i = 0; i < n; i++){
//         if(p[i].petrol == q.front().petrol && p[i].distance == q.front().distance && xOp == n)
//             return i;
//     }
//     return -1;
// }
int tour(petrolPump p[],int n){
    int deficit = 0, start = 0, cal = 0;
    for(int i = 0; i < n; i++){
        cal += (p[i].petrol-p[i].distance);
        if(cal<0){
            start = i + 1;
            deficit+= cal;
            cal=0;
        }
    }
    return (cal+deficit > 0) ? start : -1;
}
