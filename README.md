# ECSVisitor
#<h2>Descriptions</h2><br />
<p style="font-size:9pt">My first ECS test based on visitor pattern as a controller. The downsides is that visitor baseclass has so many methods, but you could still add more kinds of operations and visitorclass for different kinds of situations and than add some new attachVisitor for the new visitorbase class. With this constructions you could quickly and simple expand/scale up this structure, and letting things in the end (main.cpp) be very simplifyed. Remember this is one way to do it! there are several ways to perform an ECS. </p>
<br />
#<h2>Requirement</h2><br />
<p>
You need glm and boost installed.<br />
Its needed for handling positions etc and generating the important ID for the entity.<br />
</p>
#<h2>Compiling</h2><br />
<p>
g++ main.cpp components.cpp componentvisitors.cpp entites.cpp entitysystems.cpp -o main <br />
</p>
#<h2>Systems</h2><br />
<p>
So far it has been tested on mac os x 10.10, and it should works on linux too.<br />
But on the other hand it should works on other systems too, as long as you include glm and boost to the project.<br />
I also use g++ for compiling here, but that doesn't stop you to using VisualStudio for Windows. 
</p>