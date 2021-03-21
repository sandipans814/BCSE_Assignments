import socket
from datetime import datetime
import pickle
from key_value_client import KeyValueClient, global_dict
import sys

class TCPServer:
    def __init__(self, host, port):
        self.host = host
        self.port = port 
        self.sock = None

    def print_with_time(self, msg):
        print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {msg}")

    def configure_server(self):
        ''' Configure the server '''

        self.print_with_time('🔄 Creating server socket... ')
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.print_with_time('✅ Socket created successfully')
        except Exception as e:
            self.print_with_time(f'❌ Socket creation failed, {e}')

        self.print_with_time(f'🔄 Binding socket to {self.host}:{self.port}...')
        try:
            self.sock.bind((self.host, self.port))
            self.print_with_time('✅ Socket binding was successful')
        except Exception as e:
            self.print_with_time(f'❌ Bind failed, {e}')

    def wait_for_client(self):
        ''' Wait for a client to connect '''

        # start listening for incoming connections
        try:
            self.print_with_time('🔄 Listening for incoming connection...')
            self.sock.listen(1)

            # accept a connection
            client_sock, client_address = self.sock.accept()
            self.print_with_time(f'🤝 Accepted connection from {client_address}')
            self.handle_client(client_sock, client_address)
        
        except KeyboardInterrupt:
            self.shutdown_server()

    def handle_client(self, client_sock, client_address):
        """ Handle the accepted client's requests """

        username = client_sock.recv(1024).decode()
        if username not in global_dict:
            client = KeyValueClient(username)
            global_dict[username] = client
        else:
            client = global_dict[username]
        self.print_with_time(global_dict)
        client_sock.sendall("OK".encode('utf-8'))
        try:
            data_enc = client_sock.recv(1024)
            while data_enc:
                # client's request
                request = pickle.loads(data_enc)
                response = client.resolve(request)
                self.print_with_time(f'[ REQUEST from {client_address} ]')
                print('\n', request, '\n')

                # send response
                self.print_with_time(f'[ RESPONSE to {client_address} ]')
                client_sock.sendall(pickle.dumps(response))
                print('\n', response, '\n')

                # get more data and check if client closed the connection
                data_enc = client_sock.recv(1024)
            self.print_with_time(f'Connection closed by {client_address}')

        except OSError as err:
            self.printwt(err)

        finally:
            self.print_with_time(f'Closing client socket for {client_address}...')
            client_sock.close()
            self.print_with_time(f'Client socket closed for {client_address}')

    def shutdown_server(self):
        ''' Shutdown the server '''

        self.print_with_time('Shutting down server...')
        self.sock.close()

if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("Usage: python tcp_server.py [ port_no (int) ]")
        sys.exit()
    else:
        port = int(sys.argv[1])
    tcp_server = TCPServer('127.0.0.1', port)
    tcp_server.configure_server()
    tcp_server.wait_for_client()