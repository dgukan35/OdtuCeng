#include "MeshGraph.h"
#include "BinaryHeap.h"

// For printing
#include <fstream>
#include <iostream>
#include <sstream>

MeshGraph::MeshGraph(const std::vector<Double3>& vertexPositions,
                     const std::vector<IdPair>& edges)
{
    // TODO:
    int i;
    std::vector<IdPair>::const_iterator p;
    for(i=0;i<vertexPositions.size();i++){
        Vertex v;
        v.id = i;
        v.position3D = vertexPositions[i];
        vertices.push_back(v);
    }
    adjList.resize(vertices.size());
    for(p=edges.begin();p!=edges.end();++p){
        int v1 = p->vertexId0;
        int v2 = p->vertexId1;
        adjList[v1].push_back(&vertices[v2]);
        adjList[v2].push_back(&vertices[v1]);
    }
    
}

double MeshGraph::AverageDistanceBetweenVertices() const
{
    // TODO:
    double total = 0;
    std::list<Vertex*>::const_iterator v;
    int i;
    double distance = 0;
    for(i=0;i<vertices.size();i++){
        for(v=adjList[i].begin();v!=adjList[i].end();++v){
            distance = Double3::Distance(vertices[i].position3D,(*v)->position3D);
            total+=distance;
        }
    }
    return total/(2*MeshGraph::getedgenumbers());
}

double MeshGraph::AverageEdgePerVertex() const
{
    // TODO:
    return (double)(TotalEdgeCount())/vertices.size();
}

int MeshGraph::TotalVertexCount() const
{
    // TODO:
    int count = 0;
    int i;
    for(i=0;i<vertices.size();i++){
        count++;
    }
    return  count;
}

int MeshGraph::TotalEdgeCount() const
{
    // TODO:
    return getedgenumbers();
    
}

int MeshGraph::VertexEdgeCount(int vertexId) const
{
    // TODO:
    int i;
    int flag = 0;
    for(i=0;i<vertices.size();i++){
        if(vertices[i].id==vertexId){
            flag++;
            return adjList[i].size();
        }
    }
    if(flag==0){
        return -1;
    }
}

void MeshGraph::ImmediateNeighbours(std::vector<int>& outVertexIds,
                                    int vertexId) const
{
    // TODO:
    int i;
    std::list<Vertex*>::const_iterator v;
    outVertexIds.clear();
    for(i=0;i<vertices.size();i++){
        if(vertices[i].id==vertexId){
            for(v=adjList[i].begin();v!=adjList[i].end();v++){
                outVertexIds.push_back((*v)->id);
            }
        }
    }
    
}

void MeshGraph::PaintInBetweenVertex(std::vector<Color>& outputColorAllVertex,
                                     int vertexIdFrom, int vertexIdTo,
                                     const Color& color) const
{
    // TODO:
    int i;
    int current,current2;
    double currentdist;
    
    
    
    if(VertexEdgeCount(vertexIdFrom)==-1||VertexEdgeCount(vertexIdTo)==-1){
        outputColorAllVertex.clear();
        return;
    }
    outputColorAllVertex.resize(vertices.size());
    for(i=0;i<vertices.size();i++){
        outputColorAllVertex[i].r = 0;
        outputColorAllVertex[i].g = 0;
        outputColorAllVertex[i].b = 0;
    }
   
    
    
    BinaryHeap distanceheap;
    for(i = 0;i<vertices.size();i++){
        if(i!=vertexIdFrom){
            distanceheap.Add(i,INFINITY);
        }
    }
   
  distanceheap.Add(vertexIdFrom,0);
  std::vector<double> distances(vertices.size(),INFINITY);
  std::vector<double> prev(vertices.size(),-1);
  prev[vertexIdFrom] = -2;
  distances[vertexIdFrom] = 0;
  while(distanceheap.PopHeap(current,currentdist)){
      std::list<Vertex*>::const_iterator v;
      for(v=adjList[current].begin();v!=adjList[current].end();++v){
         
          double distance = Double3::Distance(vertices[current].position3D,(*v)->position3D);
          double newdist = currentdist + distance;
          if(newdist<distances[(*v)->id]){
              distances[(*v)->id]= newdist;
              prev[(*v)->id]=current;
              distanceheap.ChangePriority((*v)->id,newdist);
          }
      }
  }

  current2 = vertexIdTo;
  while(current2!=-2){
      
       outputColorAllVertex[current2] = color;
       current2 = prev[current2];
       
  }
  outputColorAllVertex[vertexIdFrom] = color;
  /*std::cout<<(int)outputColorAllVertex[current].r<<(int)outputColorAllVertex[current].g<<(int)outputColorAllVertex[current].b<<std::endl;*/
  
    
    
    
}

void MeshGraph::PaintInRangeGeodesic(std::vector<Color>& outputColorAllVertex,
                                    int vertexId, const Color& color,
                                    int maxDepth, FilterType type,
                                    double alpha) const
{
    // TODO:
    int i,j,k;
    int currentid;
    double currentdist;
    int count = 0;
    double num = 0;
    double newdist;
    double distance;
    int flag = 0;
    int size = 0;
    Vertex *p1;
   BinaryHeap nodeheap;
   std::vector<bool> marked(vertices.size(),false);
   std::vector<int> result;
   std::vector<double> distances(vertices.size());
   std::vector<double> tempdist(vertices.size());
   std::vector<int> prev(vertices.size(),-1);
   std::vector<int> depth(vertices.size(), -1);
   std::vector<bool> mark2(vertices.size(),false);
   marked[vertexId] = true;
   outputColorAllVertex.resize(vertices.size());
  /* previous[vertexId]=vertexId;*/
   distances[vertexId] = 0;
   tempdist[vertexId] = 0;
   /*for(i = 0;i<vertices.size();i++){
        if(i!=vertexId){
            nodeheap.Add(i,INFINITY);
        }
    }*/
   if(VertexEdgeCount(vertexId)==-1){
       
        return;
    }
    for(i=0;i<vertices.size();i++){
        outputColorAllVertex[i].r = 0;
        outputColorAllVertex[i].g = 0;
        outputColorAllVertex[i].b = 0;
    }
    nodeheap.Add(vertexId,0);
    
   /* while(size<maxDepth){
        p1 = adjList[vertexId].back();
        size++;
        if(mark2[currentid)!=true){
        currentid = p1->id;
        }
        else{
            while(!adjList[currentid].empty()){
                for(i=0;i<adjList[currentid]).size();i++){
                    if(mark2[p1->id]==false){
                        currentid = p1->id;
                        break;
                    }
                    else[
                        p1->id--;]
                }
            }
        }
    }*/
    /*std::list<Vertex*>::const_iterator p3 = adjList[vertexId+1].begin();
    for(i=0;i<5;i++){
        
        if(p3==adjList[vertexId+1].end()){
            break;
        }
        
        std::cout<<(*p3)->id<<std::endl;
        p3++;
    }*/
    /*std::cout<<getmax(vertexId,adjList,maxDepth)<<std::endl;
    std::cout<<find_last_vertex( maxDepth,  vertexId,adjList)<<std::endl;*/
    
    while(nodeheap.HeapSize()!=0){
        nodeheap.PopHeap(currentid,currentdist);
        result.push_back(currentid);
        /*if(prev[currentid]!=-1){
            std::list<Vertex*>::const_iterator it = adjList[prev[currentid]].end();
            Vertex *p = adjList[prev[currentid]].back();
            --it;
            if(currentid==(*it)->id){
                count++;
            }
        }*/
        std::list<Vertex*>::const_iterator v;
        outputColorAllVertex[currentid] = color;
       /* if(currentid==p1->id){
            break;
        }*/
        /*std::cout<<currentid<<std::endl;*/
        /*std::cout<<(int)outputColorAllVertex[currentid].r<<(int)outputColorAllVertex[currentid].g<<(int)outputColorAllVertex[currentid].b<<std::endl;*/
        if(depth[currentid]<maxDepth-1){
            count = depth[currentid];
            
        for(v=adjList[currentid].begin();v!=adjList[currentid].end();++v){
           
            if(marked[(*v)->id]==false){
                distance = Double3::Distance(vertices[currentid].position3D,(*v)->position3D);
                newdist = tempdist[currentid] + distance;
                marked[(*v)->id] = true;
                nodeheap.Add((*v)->id,num+1);
                depth[(*v)->id] = count+1;
                distances[(*v)->id] = newdist;
                tempdist[(*v)->id]=newdist;
                /*prev[(*v)->id] = currentid;*/
               /* size++;*/
               /* if(flag!=1){
                    count++;
                    flag = 1;
                }*/
                
                
               /* nodeheap.changePriority((*v)->id,num+1)*/
                num++;
            }
        }
        }
        
        flag = 0;
    }
   /* for(i=0;i<result.size();i++){
        std::cout<<result[i]<<std::endl;
    }*/
    if (type == FILTER_GAUSSIAN){
        for(i=0;i<outputColorAllVertex.size();i++){
            if(outputColorAllVertex[i].r!=0||outputColorAllVertex[i].g!=0||outputColorAllVertex[i].b!=0){
            /*std::cout<<distances[i]<<std::endl;*/
            outputColorAllVertex[i].r = (double)(outputColorAllVertex[i].r)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            outputColorAllVertex[i].g = (double)(outputColorAllVertex[i].g)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            outputColorAllVertex[i].b = (double)(outputColorAllVertex[i].b)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            (int)outputColorAllVertex[i].r;
            (int)outputColorAllVertex[i].g;
            (int)outputColorAllVertex[i].b;
            
            }
        }
    }
    if( type == FILTER_BOX){
        for(i=0;i<outputColorAllVertex.size();i++){
        if(outputColorAllVertex[i].r!=0||outputColorAllVertex[i].g!=0||outputColorAllVertex[i].b!=0){
             if(-alpha*alpha<=distances[i]&&distances[i]<=alpha){
                 outputColorAllVertex[i].r = (double)(outputColorAllVertex[i].r)*1;
                 outputColorAllVertex[i].b = (double)(outputColorAllVertex[i].b)*1;
                 outputColorAllVertex[i].g = (double)(outputColorAllVertex[i].g)*1;
                (int)outputColorAllVertex[i].r;
                (int)outputColorAllVertex[i].g;
                (int)outputColorAllVertex[i].b;
             }
             else{
                 outputColorAllVertex[i].r = 0;
                 outputColorAllVertex[i].g = 0;
                 outputColorAllVertex[i].b = 0;
                (int)outputColorAllVertex[i].r;
                (int)outputColorAllVertex[i].g;
                (int)outputColorAllVertex[i].b;
             }
        }
    }
    }
    /*std::cout<<distances[0]<<std::endl;*/
    
    return;
}
/*std::cout<<(int)outputColorAllVertex[i].r<<(int)outputColorAllVertex[i].g<<(int)outputColorAllVertex[i].b<<std::endl;*/

void MeshGraph::PaintInRangeEuclidian(std::vector<Color>& outputColorAllVertex,
                                      int vertexId, const Color& color,
                                      int maxDepth, FilterType type,
                                      double alpha) const
{
    // TODO:
    int i,j,k;
    int currentid;
    double currentdist;
    int count = 0;
    int num = 0;
    double newdist;
    double distance;
    BinaryHeap nodeheap;
   std::vector<bool> marked(vertices.size(),false);
   std::vector<int> result;
   std::vector<double> distances(vertices.size());
   /*std::vector<double> tempdist(vertices.size());*/
   std::vector<int> depth(vertices.size(), 0);
   marked[vertexId] = true;
   outputColorAllVertex.resize(vertices.size());
    distances[vertexId] = 0;
   /*tempdist[vertexId] = 0;*/
   if(VertexEdgeCount(vertexId)==-1){
       
        return;
    }
    for(i=0;i<vertices.size();i++){
        outputColorAllVertex[i].r = 0;
        outputColorAllVertex[i].g = 0;
        outputColorAllVertex[i].b = 0;
    }
    nodeheap.Add(vertexId,0);
    while(nodeheap.HeapSize()!=0){
        nodeheap.PopHeap(currentid,currentdist);
        result.push_back(currentid);
        std::list<Vertex*>::const_iterator v;
        outputColorAllVertex[currentid] = color;
        if(depth[currentid]<maxDepth){
            count = depth[currentid];
            
        for(v=adjList[currentid].begin();v!=adjList[currentid].end();++v){
           
            if(marked[(*v)->id]==false){
                distance = Double3::Distance(vertices[vertexId].position3D,(*v)->position3D);
                marked[(*v)->id] = true;
                nodeheap.Add((*v)->id,num+1);
                depth[(*v)->id] = count+1;
                distances[(*v)->id] = distance;
                num++;
            }
        }
        }
    }
        
                /*tempdist[(*v)->id]=newdist;*/
    if (type == FILTER_GAUSSIAN){
        for(i=0;i<outputColorAllVertex.size();i++){
            if(outputColorAllVertex[i].r!=0||outputColorAllVertex[i].g!=0||outputColorAllVertex[i].b!=0){
            /*std::cout<<distances[i]<<std::endl;*/
            outputColorAllVertex[i].r = (double)(outputColorAllVertex[i].r)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            outputColorAllVertex[i].g = (double)(outputColorAllVertex[i].g)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            outputColorAllVertex[i].b = (double)(outputColorAllVertex[i].b)*(std::exp(-(distances[i]*distances[i])/(alpha*alpha)));
            (int)outputColorAllVertex[i].r;
            (int)outputColorAllVertex[i].g;
            (int)outputColorAllVertex[i].b;
            
            }
        }
    }
    if( type == FILTER_BOX){
        for(i=0;i<outputColorAllVertex.size();i++){
        if(outputColorAllVertex[i].r!=0||outputColorAllVertex[i].g!=0||outputColorAllVertex[i].b!=0){
             if(-alpha*alpha<=distances[i]&&distances[i]<=alpha){
                 outputColorAllVertex[i].r = (double)(outputColorAllVertex[i].r)*1;
                 outputColorAllVertex[i].b = (double)(outputColorAllVertex[i].b)*1;
                 outputColorAllVertex[i].g = (double)(outputColorAllVertex[i].g)*1;
                (int)outputColorAllVertex[i].r;
                (int)outputColorAllVertex[i].g;
                (int)outputColorAllVertex[i].b;
             }
             else{
                 outputColorAllVertex[i].r = 0;
                 outputColorAllVertex[i].g = 0;
                 outputColorAllVertex[i].b = 0;
                (int)outputColorAllVertex[i].r;
                (int)outputColorAllVertex[i].g;
                (int)outputColorAllVertex[i].b;
             }
        }
    }
    }
                
    return;
}


void MeshGraph::WriteColorToFile(const std::vector<Color>& colors,
                                 const std::string& fileName)
{
    // IMPLEMENTED
    std::stringstream s;
    for(int i = 0; i < static_cast<int>(colors.size()); i++)
    {
        int r = static_cast<int>(colors[i].r);
        int g = static_cast<int>(colors[i].g);
        int b = static_cast<int>(colors[i].b);

        s << r << ", " << g << ", " << b << "\n";
    }
    std::ofstream f(fileName.c_str());
    f << s.str();
}

void MeshGraph::PrintColorToStdOut(const std::vector<Color>& colors)
{
    // IMPLEMENTED
    for(int i = 0; i < static_cast<int>(colors.size()); i++)
    {
        std::cout << static_cast<int>(colors[i].r) << ", "
                  << static_cast<int>(colors[i].g) << ", "
                  << static_cast<int>(colors[i].b) << "\n";
    }
}