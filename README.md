## Feed Larry the Lobster

In this program you will feed larry the lobster some food! Should be fun...

# How to Run
I am not using CLION so please use the Makefile I made. To run main.cpp use: make run, for tests.cpp make tests. 

# Project Description

Classes: Pet(abstract), Lobster (Inherits from Pet), Stomache (Component class of Lobster), Family(Unrelated class)

# How it Works

Simply put, the Lobster class inherits all the field variables, and non abstract methods from the pet class. These fields include, name, owner and foods the pet eats. The Lobster class has two new fields, favorite_food and stomache which represent his favorite food and his stomache. The Stomache is a component of a lobster, its main function is to store the food of the lobster and prevent him from over eating. A stomache object has the fields, hunger_level, STOMACHE_CAPACITY and the contents on the stomache. The Family class is simply a collection of family members and goodbye messages. If you remove a family member that member says goodbye. The removeMember() function of the Family class is random. The family appears in the virtual pet feeding game that is made in the main.cpp file. 
