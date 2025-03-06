### 朴素Dijkstra算法
#### 原题链接
https://www.acwing.com/problem/content/851/
#### 核心思想
Dijkstra算法的核心思想是==贪心==，进行`n`轮迭代，每一轮确定一个点到起点的最短距离，确定之后再用这个点更新到其他点的最短距离并加入集合`S`（集合S是已经确定最短距离的点的集合）。
#### 时间复杂度$O(n^2)$
==朴素Dijkstra适合稠密图==
#### 代码
```cpp
int Dijkstra()
{
    memset(dist, 0x3f,sizeof dist);     //初始化距离  0x3f代表无限大

    dist[1]=0;  //第一个点到自身的距离为0

    for(int i=0;i<n;i++)      //有n个点所以要进行n次 迭代
    {
        int t=-1;       //t存储当前访问的点

        for(int j=1;j<=n;j++)   //这里的j代表的是从1号点开始
            if(!st[j]&&(t==-1||dist[t]>dist[j]))     
                t=j;

        st[t]=true;   

        for(int j=1;j<=n;j++)           //依次更新每个点所到相邻的点路径值
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }

    if(dist[n]==0x3f3f3f3f) return -1;  //如果第n个点路径为无穷大即不存在最低路径
    return dist[n];
}
```
### 堆优化Dijkstra算法
#### 原题链接
https://www.acwing.com/problem/content/852/
#### 核心思想
在朴素Dijkstra的基础上，将找点`t`的过程用小根堆优化。外层循环是判断堆是否为空，内层循环还是找点，总的时间复杂度为$O(mlog{n})$ 
#### 代码
```cpp
int dijkstra(){

    dis[1] = 0;

    //定义小根堆，pair第一项存距离

    priority_queue<PII, vector<PII>, greater<PII> > heap;

    heap.push({0, 1});

  

    while(heap.size()){

        auto t = heap.top();

        heap.pop();

        int ver = t.second, distance = t.first;

        if(st[ver]) continue;

        st[ver] = true;

  

        for(int i = h[ver]; i != -1; i = ne[i]){

            int j = e[i];

            if(dis[j] > distance + w[i]){

                dis[j] = distance + w[i];

                heap.push({dis[j], j});

            }

        }

  

    }

  

    if(dis[n] == 0x3f3f3f3f) return -1;

    return dis[n];

}
```