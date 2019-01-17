from flask import Flask, render_template, redirect
from model import *
from collections import defaultdict

app = Flask(__name__)

@app.route('/')
def index():
    return redirect('/requests/1')

@app.route('/requests')
def get_requests():
    return redirect('/requests/1')

@app.route('/requests/<int:page>')
def get_requests_per_page(page):
    requests = Request.where().limit(20, (page - 1) * 20).select()
    cnt = Request.where().count()
    page_end = cnt / 20 + (cnt % 20 != 0)
    return render_template('requests.html', pages=range(max(1, page-1), min(page_end+1, page+4)), requests=requests, page_end=page_end, page_now=page)

@app.route('/header/<int:requestid>')
def get_header(requestid):
    headers = Header.where(requestid=requestid).select()
    return render_template('headers.html', requestid=requestid, headers=headers)

@app.route('/sort/host')
def get_sort_host():
    hostdictbytimes = defaultdict(int)
    hostdictbyclient = defaultdict(set)
    for request in Request.where().select():
        hostdictbytimes[request.host] += 1
        hostdictbyclient[request.host].add(request.clientip)

    by_times_host = sorted(hostdictbytimes.keys(), key=lambda k: hostdictbytimes[k])[::-1]
    by_times_cnt =  sorted(hostdictbytimes.values())[::-1]

    by_client_host = sorted(hostdictbyclient.keys(), key=lambda k: len(hostdictbyclient[k]))[::-1]
    by_client_cnt =  sorted([len(s) for s in hostdictbyclient.values()])[::-1]

    return render_template('hostsort.html', by_times_host=by_times_host, by_times_cnt=by_times_cnt, by_client_host=by_client_host, by_client_cnt=by_client_cnt)

@app.route('/sort/client')
def get_sort_clinet():
    clientdict = defaultdict(int)

    for request in Request.where().select():
        clientdict[request.clientip] += 1

    clients = sorted(clientdict.keys(), key=lambda k: clientdict[k])[::-1]
    cnts = sorted(clientdict.values())[::-1]

    return render_template('clientsort.html', clients=clients, cnts=cnts)

@app.route('/client/<clientip>')
def get_client(clientip):
    hostcnt = defaultdict(int)

    for request in Request.where(clientip=clientip).select():
        hostcnt[request.host] += 1

    hosts = sorted(hostcnt.keys(), key=lambda k: hostcnt[k])[-1:-11:-1]
    times = sorted(hostcnt.values())[-1:-11:-1]

    return render_template('client.html', clientip=clientip, hosts=hosts, cnts=zip(hosts, times))


@app.route('/host/<hostname>')
def get_host(hostname):
    clientcnt = defaultdict(int)

    for request in Request.where(host=hostname).select():
        clientcnt[request.clientip] += 1

    clients = sorted(clientcnt.keys(), key=lambda k: clientcnt[k])[-1:-11:-1]
    times = sorted(clientcnt.values())[-1:-11:-1]

    return render_template('host.html', hostname=hostname, clients=clients, cnts=zip(clients, times))

if __name__ == '__main__':
    app.run(host='0.0.0.0')
