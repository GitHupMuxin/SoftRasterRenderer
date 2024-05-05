运行需要依赖的外部库 Assimp  
用C++写的软光栅，用了Assimp来读取模型, openCV来输出图片和std_image来读取贴图。其余的全是自己手搓(所以某些功能可能还没完成以及存在各种bug)。后续可能自己写一个读取模型的库，那时候就不用链接assimp了。  
下面的一些跑出来的结果，光照模型使用的是billnnPhong的方式
![image](TinyRender/TinyRender/outPut/mary.png)
![image](TinyRender/TinyRender/outPut/nanosuit.png)
![image](TinyRender/TinyRender/outPut/planet.png)
![image](TinyRender/TinyRender/outPut/rock.png)
