$TTL    300
@                       1D IN SOA       example.cl. hostmaster.example.cl. (
                                        2016100501     ; serial
                                        3H              ; refresh
                                        15M             ; retry
                                        4W              ; expiry
                                        600 )            ; minimum

                        1D IN NS        ns.example.cl.
			IN MX 10	mail.example.cl. 


$ORIGIN example.cl.
                IN    	A	      19.19.19.19
ns      600     IN      A       19.19.19.20
www     120     IN      A       19.19.19.21
mail	  120     IN	    A	      19.19.19.22 
