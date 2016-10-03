##BIND's Default Policy for Recursion

>In versions of BIND prior to (and including) BIND 9.4.1, the default behavior of BIND servers was to allow recursion 
for all clients (unless otherwise specified.)

Because open recursion has some undesirable side-effects (such as allowing a server to be exploited by attackers 
targeting a victim with DNS amplification attacks) the default behavior was changed in BIND 9.4.1-P1. 
Since 9.4.1-P1, unless an ACL is explicitly specified in the "allow-recursion" statement, the default access list
is set to "localnets; localhost;" (in other words, the local server machine and those broadcast domains for which 
the server has a network interface configured at the time named is started.)
