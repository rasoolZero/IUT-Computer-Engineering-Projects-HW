print("# Kapture is setting up")
import pyshark,sys

counter = 0
retransmissions = 0

timeout=20
if(len(sys.argv) > 1):
    timeout = int(sys.argv[1])


capture = pyshark.LiveCapture(
        interface='lo',bpf_filter = "port 4040")

print("# Kapture is now sniffing for {} seconds".format(timeout))
capture.sniff(timeout=timeout)

for i in range(len(capture)):
    counter+=1
    print("### packet captured\tcounter:",counter)
    if "retransmission" in "{}".format(capture[i]) :
        #print("\tit is a retransmission")
        retransmissions+=1
    
capture.close()
#capture.eventloop.close()
print("## Total Packets captured :",counter)
print("## Total Retransmissions :",retransmissions)
exit()
