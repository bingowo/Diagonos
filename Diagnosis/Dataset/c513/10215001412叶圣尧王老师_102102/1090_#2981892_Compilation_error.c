

<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">
  <link rel="icon" href="/static/favicon.ico">
  <link rel="stylesheet" href="/static/node_modules/npm-font-open-sans/open-sans.css">
  <link rel="stylesheet" href="/static/node_modules/font-awesome/css/font-awesome.min.css">
  <link rel="stylesheet" href="/static/css/app.min.css?v=1620609533">
  <link rel="stylesheet" href="/static/node_modules/simplemde/dist/simplemde.min.css">
  <script src="/static/node_modules/jquery/dist/jquery.min.js"></script>
  <!-- Global site tag (gtag.js) - Google Analytics -->
  <script>
    window.dataLayer = window.dataLayer || [];
    function gtag(){dataLayer.push(arguments);}
    gtag('js', new Date());
    

    gtag('config', 'UA-136856183-1');

    // Feature detects Navigation Timing API support.
    if (window.performance) {
      // Gets the number of milliseconds since page load
      // (and rounds the result since the value must be an integer).
      var timeSincePageLoad = Math.round(performance.now());

      // Sends the timing event to Google Analytics.
      gtag('event', 'timing_complete', {
        'name': 'load',
        'value': timeSincePageLoad,
        'event_category': 'JS Dependencies'
      });
    }
  </script>
  <script async src="https://www.googletagmanager.com/gtag/js?id=UA-136856183-1"></script>

  
  
  <title>ECNU Online Judge</title>
</head>

<body class="local-body">







<div class="ui top fixed menu" id="navbar">

  <div class="ui container" id="navbar-small">
    <div class="ui pointing dropdown link item">
      <i class="content icon"></i>
      <span class="text"><b>EOJ</b></span>
      <div class="menu">
        <a class="item" href="/">首页</a>
        <a class="item" href="/contest/">比赛</a>
        <a class="item" href="/problem/list/">题目集</a>
        <a class="item" href="/contest/gym/">作业</a>
      </div>
    </div>

    <div class="right menu">
      
  
    <div class="item"><a class="ui primary button" href="/login/?next=/login/">登入</a></div>
  

    </div>
  </div>

  <div class="ui container" id="navbar-large">
    <a class=" item" href="/"><i class="home icon"></i>首页</a>
    <a class=" item" href="/contest/"><i class="flag icon"></i>比赛</a>
    <a class="item " href="/problem/"><i class="book icon"></i>题目集</a>
    <a class=" item" href="/contest/gym/"><i class="paper plane icon"></i>作业</a>


    <div class="right menu">
      <div class="ui category search item massive-search">
        <div class="ui transparent icon input">
          <input class="prompt" type="text" placeholder="搜索...">
          <i class="search link icon"></i>
        </div>
        <div class="results"></div>
      </div>
      
  
    <div class="item"><a class="ui primary button" href="/login/?next=/login/">登入</a></div>
  

    </div>
  </div>
</div>
  <div class="pusher">
  <div class="ui main container">
  
    <h1 class="ui header">登录</h1>
  
    


  




  

  

  

  

  



<form class="ui form " action="/login/?next=/api/submission/%3Fc%3D513%26p%3D1090" method="post" enctype="multipart/form-data">
  <input type='hidden' name='csrfmiddlewaretoken' value='xoi47FJW27g26wrqcfrrG4956UK7RcSUFPM6fxMKhRTugn7f6xC2oNr1OS6kP73K' />
  <input type="hidden" name="next" value="/login/?next=/api/submission/%3Fc%3D513%26p%3D1090">
  <div class="ui error message">
    <div class="header">存在问题！</div>
    <ul class="list">
      
        
      
        
      
        
      
        
      
        
      
      
    </ul>
  </div>

  
    <div class="field ">
      
        
          <label for="id_username">用户名或邮箱:</label>
        
        <input autofocus="" id="id_username" name="username" placeholder="" required="" type="text"/>
      
    </div>
  
    <div class="field ">
      
        
          <label for="id_password">密码:</label>
        
        <input id="id_password" name="password" placeholder="" required="" type="password"/>
      
    </div>
  
    <div class="field ">
      
        <label for="id_captcha_1">小学数学题:</label>
        <img src="/captcha/image/df56e8eb56a1ee1496b1cb549476951d17ccf25b/" alt="captcha" class="captcha" />
<input type="hidden" name="captcha_0" value="df56e8eb56a1ee1496b1cb549476951d17ccf25b" required id="id_captcha_0"><input type="text" name="captcha_1" required id="id_captcha_1" autocapitalize="off" autocomplete="off" autocorrect="off" spellcheck="false">
      
    </div>
  
    <div class="field ">
      
        <div class="ui checkbox">
          <input class="hidden" id="id_remember_me" name="remember_me" placeholder="" type="checkbox"/>
          <label>记住我</label>
        </div>
      
    </div>
  
    <div class="field ">
      
        
        <input id="id_public_key" name="public_key" placeholder="" type="hidden" value="-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDLvtWGf6qTLFefIHJ0eWyscHEf
XuZvQOt9yZKfm9niuXnSSaVsr+9tJ0703vDsGDRvDWj7n9RqkVU+makC9nTRrNY+
VHSPjQf6XxsFghF4c1gXw7FvNGDjyDAt9PYU3GiCJ7WpltdPdx0n0tfsPlvei0hh
a+Xl5slhZcD09SwDHQIDAQAB
-----END PUBLIC KEY-----"/>
      
    </div>
  
  
    <button type="submit" class="ui positive button">确定</button>
  
</form>

<script>
  $(".ui.form").submit(function() {
    $(this).prop('loading', true);
  });
</script>
  <p><a href="/account/password_reset/">忘记密码</a> | <a href="/register/">注册账号</a></p>


  </div>
  <div class="ui inverted vertical footer segment">
  <div class="ui container">
    <div class="ui stackable inverted divided equal height stackable grid">
      <div class="three wide column">
        <h4 class="ui inverted header">服务</h4>
        <div class="ui inverted link list">
          <a href="/" class="item">首页</a>
          <a href="/feedback/" class="item">反馈</a>
          <a href="/polygon/" class="item">Polygon</a>
          <a href="/wiki/index.php?title=Main_Page" class="item">Wiki</a>
        </div>
      </div>
      <div class="three wide column">
        <h4 class="ui inverted header">开源</h4>
        <div class="ui inverted link list">
          <a href="https://github.com/ultmaster/eoj3" class="item">Github</a>
          <a href="https://github.com/ultmaster/ejudge" class="item">eJudge</a>
        </div>
      </div>
      <div class="seven wide column">
        <h4 class="ui inverted header">关于我们</h4>
        <p>团队: <a href="https://github.com/ultmaster">@ultmaster</a>, <a href="https://github.com/zerolfx">@zerol</a>, <a href="https://github.com/kblackcn">@kblack</a>.<br>
        联系方式: <a href="mailto:acmsupport@admin.ecnu.edu.cn">acmsupport@admin.ecnu.edu.cn</a></p>
      </div>
    </div>
  </div>
</div>
  </div>


<script>
  MathJax = {
    tex: {
      inlineMath: [
        ['\\(', '\\)'],
        ['$', '$']
      ],
      displayMath: [
        ['$$', '$$'],
        ['\\[', '\\]']
      ],
    }
  };
</script>
<script src="/static/node_modules/mathjax/es5/tex-chtml-full.js"></script>
<script src="/static/node_modules/moment/moment.js"></script>
<script src="/static/node_modules/clipboard/dist/clipboard.min.js"></script>
<script src="/static/node_modules/js-cookie/src/js.cookie.js"></script>
<script src="/static/node_modules/jquery-address/src/jquery.address.js"></script>
<script src="/static/node_modules/lodash/lodash.min.js"></script>
<script src="/static/node_modules/semantic-ui-less/semantic.js"></script>
<script src="/static/node_modules/simplemde/dist/simplemde.min.js"></script>
<script src="/static/node_modules/ace-builds/src-noconflict/ace.js"></script>
<script src="/static/node_modules/ace-builds/src-noconflict/ext-language_tools.js"></script>
<script src="/static/node_modules/underscore/underscore.js"></script>
<script src="/static/node_modules/semantic-ui-calendar/dist/calendar.min.js"></script>
<script src="/static/js/lang-detector.js?v=1620609533"></script>
<script src="/static/js/markdown.js?v=1620609533"></script>
<script src="/static/js/longpoll.js?v=1620609533"></script>
<script src="/static/js/input.file.js?v=1620609533"></script>
<script src="/static/js/app.js?v=1620609533"></script>
<script src="/static/js/post.js?v=1620609533"></script>
<script src="/static/js/submit.js?v=1620609533"></script>

<script src="/static/js/forge.min.js"></script>
<script>
  function doRSA(stringToBeEncrypted, pubkey) {
    var publicKey = forge.pki.publicKeyFromPem(pubkey);
    var buffer = forge.util.createBuffer(stringToBeEncrypted, 'utf8');
    var binaryString = buffer.getBytes();
    var encrypted = publicKey.encrypt(binaryString, 'RSA-OAEP', {
        md: forge.md.sha256.create(),
        mgf1: {
            md: forge.md.sha256.create()
        }
    });
    return forge.util.encode64(encrypted);
  }

  var passwords = $("*[name='password'], *[name='repeat_password']");
  passwords.val("");
  var public_key = $("*[name='public_key']").val();
  $("form").submit(function () {
    passwords.each(function () {
      $(this).val(doRSA($(this).val(), public_key));
    })
  });
</script>


</body>
</html>