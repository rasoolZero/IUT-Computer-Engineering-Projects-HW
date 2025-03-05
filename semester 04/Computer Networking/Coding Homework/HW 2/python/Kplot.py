import json
import matplotlib.pyplot as plt
import sys
import argparse




def chart(args, data):
    if args.protocol == 'udp':
        sum_string = 'sum'
    else:
        sum_string = 'sum_sent'

    debit = []
    intervals = data['intervals']
    for i in intervals:
        debit.append(i['sum']['bits_per_second'])

    plt.plot(debit, label='Bandwitdh (per second)')

    plt.axhline(data['end'][sum_string]['bits_per_second'], color='r', label='Avg bandwidth')

    plt.title('{}, {}, {:.3}GB file'.format(data['start']['timestamp']['time'],
                                         data['start']['test_start']['protocol'],
                                         data['end'][sum_string]['bytes']/1000000000))
    plt.legend()
    plt.yscale('linear')
    plt.ylim(bottom=0)
    plt.ylabel('bit/s')
    plt.xlabel('time interval')
    plt.show()
    
    
    
def main(argv):
    parser = argparse.ArgumentParser(description='Simple python iperf JSON data vizualiser. Use -J option with iperf to have a JSON output.')
    parser.add_argument('-i','--input', nargs='?', help='JSON output file from iperf')
    args = parser.parse_args(argv)
    with open(args.input) as f:
        data = json.load(f)
        if data['start']['test_start']['protocol'] == 'UDP':
            args.protocol = 'udp'
        else:
            args.protocol = 'tcp'
        chart(args, data)


if __name__ == '__main__':
    main(sys.argv[1:])
    
    
