# ECSVisitor
#<h2>ecsvisitor</h2><br />
<p style="font-size:9pt">My first ECS test based on visitor pattern as a controller. The downsides is that visitor baseclass has so many methods, but you could still add more kinds of operations and visitorclass for different kinds of situations and than add some new attachVisitor for the new visitorbase class. With this constructions you could quickly and simple expand/scale up this structure, and letting things in the end (main.cpp) be very simplifyed. Remember this is one way to do it! there are several ways to perform an ECS. </p>
<br />
<p>
Requirement:<br/>
You need glm and boost installed.<br />
It only need it for handling positions etc and generating the important ID for the entity.<br />
Compile with:<br />
g++ main.cpp components.cpp componentvisitors.cpp entites.cpp entitysystems.cpp -o main <br />
</p>
