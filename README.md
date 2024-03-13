# Logic Gates and Events

---

### Introduction

This is a culmination of many months of work. I've tried to implement a Logic Gate simulator, somewhat unsuccessfully, 
without the use of some sort of event driven system. Then I came across the Observer, and realized the ideas are a match
made in heaven. I can have my nodes be either Publishers, Subscribers, or Both! 

By using the Observer Pattern, we can simply connect up the nodes to each other, and then when the state is changed, the 
states of connected nodes will be propogated automatically.


---

