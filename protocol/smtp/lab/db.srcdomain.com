$TTL    300
@                       1D IN SOA       srcdomain.com. hostmaster.srcdomain.com. (
                                        2016101701     ; serial
                                        3H              ; refresh
                                        15M             ; retry
                                        4W              ; expiry
                                        600 )            ; minimum

                        1D IN NS        ns.srcdomain.com.
			                     IN MX 10	server.srcdomain.com. 


$ORIGIN srcdomain.com. 
                IN      TXT	"v=spf1 mx -all"
ns      600     IN      A       192.168.125.45
www     120     IN      A       192.168.125.46
server	120     IN	    A       192.168.125.125
