import socket
from datetime import datetime
import pickle
import sys

class TCPClient:

    commands = ("get", "put", "upgrade", "getother", "putother")

    def __init__(self, username):
        self.username = username
        self.sock = None

    def print_with_time(self, msg):
        print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {msg}")

    def configure_client(self, host, port):
        self.print_with_time('🔄 Creating client socket...')
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.print_with_time('✅ Socket created successfully')

        except Exception as e:
            self.print_with_time(f'❌ Socket creation failed, {e}')

        self.print_with_time(f'🔄 Connecting to {host}:{port}...')
        try:
            self.sock.connect((host, port))
            self.print_with_time('✅ Socket connection was successful')
        except Exception as e:
            self.print_with_time(f'❌ Bind failed')

    def parse( self, args: list[str] ):
        
        request = []
        i = 0
        while i < len(args):
            if ( args[i].lower() == "get" ):
                if( i == (len( args ) - 1) or args[i + 1].lower() in TCPClient.commands):
                    return 0, request
                request.append({ "method": "get", "key": args[i + 1]})
                i += 1
            elif ( args[i].lower() == "put" ):
                if( i > (len( args ) - 3) or args[i + 1].lower() in TCPClient.commands or args[i + 2].lower() in TCPClient.commands):
                    return 0, request
                request.append({ "method": "put", "key": args[i + 1], "value": args[i + 2] })
                i += 2
            elif ( args[i].lower() == "upgrade" ):
                if( i == (len( args ) - 1) or args[i + 1].lower() in TCPClient.commands ):
                    return 0, request
                request.append({ "method": "upgrade", "password": args[i + 1] })
                i += 1
            elif ( args[i].lower() == "getother" ):
                if( i > (len( args ) - 3) or args[i + 1].lower() in TCPClient.commands or args[i + 2].lower() in TCPClient.commands):
                    return 0, request
                request.append({ "method": "getother", "username": args[i + 1], "key": args[i + 2] })
                i += 2
            elif ( args[i].lower() == "putother" ):
                if( i > (len( args ) - 4) or args[i + 1].lower() in TCPClient.commands or args[i + 2].lower() in TCPClient.commands or args[i + 3].lower() in TCPClient.commands):
                    return 0, request
                request.append({ "method": "putother", "username": args[i + 1], "key": args[i + 2], "value": args[i + 3] })
                i += 3
            else:
                return 0, request
            i += 1
        return 1, request

    def interact(self):
        try:
            self.sock.sendall(self.username.encode('utf-8'))
            var = self.sock.recv(1024).decode()
            print(var)
            if var != "OK":
                self.print_with_time("Some error occurred, please try again later")
                return
            while True:
                name = input("$ ")
                if name == "q" or name == "quit":
                    self.sock.close()
                    return
                code, request = self.parse(list(filter(lambda x: x != '', name.split(" "))))
                if (code == 0):
                    print("Invalid arguments, rejecting...")
                    continue
                else:
                    print(request)
                # self.sock.sendall(f"Sairyo".encode('utf-8'))
                self.sock.sendall(pickle.dumps(request))
                response = pickle.loads(self.sock.recv(1024))
                self.print_with_time(response)
        
        except KeyboardInterrupt:
            self.sock.close()


if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("Usage: python tcp_client.py [ port_no (int) ]")
        sys.exit()
    else:
        port = int(sys.argv[1])
    username = input("Enter username: ")
    while username in TCPClient.commands:
        print("This keyword cannot be used as username, please try again.\n")
    tcp_client = TCPClient(username)
    try:
        tcp_client.configure_client('127.0.0.1', port)
    except:
        sys.exit()
    tcp_client.interact()