from model import *
from collections import defaultdict


def sort_urls(clientip):
    urlcnt = defaultdict(int)

    for request in Request.where(clientip=clientip).select():
        urlcnt[request.host + request.url] += 1

    return zip(sorted(urlcnt.keys(), key=lambda k: urlcnt[k])[::-1], sorted(urlcnt.values())[::-1])


if __name__ == "__main__":
    for kv in sort_urls("211.71.149.249")[:10]:
        print(kv[0], kv[1])
