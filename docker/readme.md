## Docker normally used command

### Start & Help

**start docker**  : `systemctl start docker`  

**stop docker**   : `systemctl stop docker`

**restart docker**: `systemctl restart docker`  

**check docker**  : `systemctl status docker`  

**power on VM with docker** : `systemctl enable docker`  

**see docker info**         : `docker info`  

**see docker general help** : `docker --help`  

**see specific command help**  : `deocker [command] --help`  

### Image

**list all images**: `docker images`  

**search images in repo**: `docker search [name] --limit [number of results]`  

**download from repo**:  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull [image name]`   This command will download latest version equal to `docker pull [image name]:latest`  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull [image name]:version`   This command will download specific version  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull ubuntu` &nbsp;&nbsp;&nbsp;&nbsp; `docker pull ubuntu:20.04`  

**check image stats** : `docker system df`  

**delete images** : `docker rmi [-f] [img_id or img name]`


### Container

**run a image** : `docker run [options] image [command]`  
options:
&nbsp;&nbsp;&nbsp;&nbsp;`--name`: name for container
&nbsp;&nbsp;&nbsp;&nbsp;`-d`    : run container in background(detached mode)  
&nbsp;&nbsp;&nbsp;&nbsp;`-i`    : run docker in interative mode, normally used with '-t'  
&nbsp;&nbsp;&nbsp;&nbsp;`-t`    : allocate a pesudo TTY,normally used with `-i`  
&nbsp;&nbsp;&nbsp;&nbsp;`-P`    : random port  
&nbsp;&nbsp;&nbsp;&nbsp;`-p`    : specific port `-p 8080:80`  

**see all running image** : `docker ps [options]`  

**inspect container**     : `docker inspect [id]`  

**restart,stop,kill**     : `docker restart/stop/kill [id or name]`

**delete stopped container**  : `docker rm [option] [id or name]` using -f in option will forcely delete 

**exit container but keep running** : `ctrl+p+q`

**exit container and shut down it** : `exit`

**re-enter a running container** : `docker exec [option] [id] command [ARG]`
options:
&nbsp;&nbsp;&nbsp;&nbsp;`-d`    : run container in background(detached mode)  
&nbsp;&nbsp;&nbsp;&nbsp;`-i`    : run docker in interative mode, normally used with '-t'  
&nbsp;&nbsp;&nbsp;&nbsp;`-t`    : allocate a pesudo TTY,normally used with `-i`  

There is also another way `docker attach [id]`. But first way is recommanded, since it opens a new process. Once that process is interruptly stopped, the container can still survive because of existance of old process.  

**cp file from container** : `docker cp [id:path] path`  
e.g. `docker cp a12619d47097:/tmp/a.txt a.txt`

**export and import**
&nbsp;&nbsp;&nbsp;&nbsp;`export` : `docker export a12619d47097 > abcd.tar.gz`
&nbsp;&nbsp;&nbsp;&nbsp;`import` : `cat abcd.tar.gz | docker import - wwu/ubuntu:20.04`

export will export everything inside a container to host machine. Import will transfer tar to a image.

**commit** `docker commit -m='' -a='' [id] [name1/name2]:[tag]`

## Container volume 

When we start a container, we can use volume to link container and host machine. They will shar a common directory.  
formula   `docker run [option] --priviledge=true -v [host dir:contariner dir:[rw/ro]] [--name name] [image]:[tag]`  
example   `docker run -it --privileged=true -v /home/pwdis123/Desktop:/home:ro ubuntu:20.04`
`rp` means we can only read insidi container

**volume heritage** `docker run [option] --priviledge=true - -volume-from [father id] [host dir:contariner dir:[rw/ro]] [--name name] [image]:[tag]`

## Docker file

**COMMAND**

`FROM`: base image, normally is a existed image, the first command in docker file  

`MAINTAINER` : name and e-mail of author  

`RUN` : terminal command that needed to be used when build container. For example, when we have a base ubuntu:20.04 image, if we want to add vim tools, we have to run
`apt-get install vim` in the container. Now we can write `RUN apt-get install vim`, it will help us execute `apt-get install vim`.
