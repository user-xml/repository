<%--
  Created by IntelliJ IDEA.
  User: XML
  Date: 2018/11/9
  Time: 14:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>抽奖</title>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/static/css/demo.css" type="text/css"/>
    <script type="text/javascript" src="${pageContext.request.contextPath}/static/js/jquery.min.js"></script>
    <script type="text/javascript" src="${pageContext.request.contextPath}/static/js/awardRotate.js"></script>
    <script type="text/javascript">
        $(function () {
            var count = 1000;
            var flag = true;
            var rotateTimeOut = function () {
                $('#rotate').rotate({
                    angle: 0,
                    animateTo: 2160,
                    duration: 8000,
                    callback: function () {
                        alert('网络超时，请检查您的网络设置！');
                    }
                });
            };
            var bRotate = false;
            var rotateFn = function (awards, angles, txt) {
                console.log(txt);
                bRotate = !bRotate;
                $('#rotate').stopRotate();
                $('#rotate').rotate({
                    angle: 0,
                    animateTo: angles + 1800,
                    duration: 8000,
                    callback: function () {
                        alert(txt);
                        bRotate = !bRotate;
                    }
                })
            };

            $('.pointer').click(function () {
                if (bRotate) {
                    return;
                }

                if (count-- == 0) {
                    flag = false;
                }
                if (flag) {
                    console.log("次数还剩--->" + count);

                    var item = getItem();
                    switch (item) {
                        case 0:
                            //var angle = [26, 88, 137, 185, 235, 287, 337];
                            rotateFn(0, 337, '未中奖');
                            break;
                        case 1:
                            //var angle = [88, 137, 185, 235, 287];
                            rotateFn(1, 26, '免单4999元');
                            break;
                        case 2:
                            //var angle = [137, 185, 235, 287];
                            rotateFn(2, 88, '免单50元');
                            break;
                        case 3:
                            //var angle = [137, 185, 235, 287];
                            rotateFn(3, 137, '免单10元');
                            break;
                        case 4:
                            //var angle = [185, 235, 287];
                            rotateFn(4, 185, '免单5元');
                            break;
                        case 5:
                            //var angle = [185, 235, 287];
                            rotateFn(5, 185, '免单5元');
                            break;
                        case 6:
                            //var angle = [235, 287];
                            rotateFn(6, 235, '免单10元');
                            break;
                        case 7:
                            //var angle = [287];
                            rotateFn(7, 287, '免单5元');
                            break;
                    }
                } else {
                    alert("您的次数已经用完！");
                    return;
                }
            });
        });

    //抽奖算法
        function getItem() {
            var arr = new Array(49990,10,998,4988,9998,9998,4988,4998);
            var leng = 0 ;
            for(var i = 0; i < arr.length; i++){
                leng+=arr[i];                                     //获取总数
            }
            for(var i=0; i<arr.length; i++){
                var random = parseInt(Math.random()*leng);       //获取 0-总数 之间的一个随随机整数
                if(random<arr[i]){
                    return i;                                     //如果在当前的概率范围内,得到的就是当前概率
                }
                else {
                    leng-=arr[i];                                //否则减去当前的概率范围,进入下一轮循环
                }
            }
        }
    </script>
</head>
<body>
<div class="turntable-bg">
    <div class="pointer"><img src="${pageContext.request.contextPath}/static/img/pointer.png" alt="pointer"/></div>
    <div class="rotate"><img id="rotate" src="${pageContext.request.contextPath}/static/img/turntable.png"
                             alt="turntable"/></div>
</div>

</body>
</html>