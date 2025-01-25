package com.company;

//Class Time Problem Solving
//Name: Hasibul Hasan Nirob
//ID: 011201031

import java.util.*;

public class HasFullCycle {

    static class Graph
    {
        int V;
        Vector<Integer>[] adj;

        Graph(int V)
        {
            this.V = V;
            this.adj = new Vector[V];
            for (int i = 0; i < V; i++)
                adj[i] = new Vector<>();
        }
        void addEdge(int u, int v)
        {
            adj[u].add(v);
        }

        boolean isCycle()
        {
            int[] in_degree = new int[this.V];
            Arrays.fill(in_degree, 0);
            for (int u = 0; u < V; u++)
            {
                for (int v : adj[u])
                    in_degree[v]++;
            }
            Queue<Integer> q = new LinkedList<Integer>();
            for (int i = 0; i < V; i++)
                if (in_degree[i] == 0)
                    q.add(i);
            int cnt = 0;
            Vector<Integer> top_order = new Vector<>();
            while (!q.isEmpty())
            {

                int u = q.poll();
                top_order.add(u);
                for (int itr : adj[u])
                    if (--in_degree[itr] == 0)
                        q.add(itr);
                cnt++;
            }
            if (cnt != this.V)
                return true;
            else
                return false;
        }
    }
    public static void main(String[] args)
    {
        Graph g = new Graph(6);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 0);

        if (g.isCycle())
            System.out.println("Yes there is a cycle :)");
        else
            System.out.println("No cycle here :(");
    }
}
